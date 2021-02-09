#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  EPS            (1e-06)
#define  is_zero(d)     (fabs(d) < EPS)
#define  deg2rad(d)     ((d)*M_PI/180.0)    /* degree to radian */
#define  rad2deg(d)     ((d)*180.0/M_PI)    /* radian to degree */
#define  min(a,b)       ((a)<(b)? (a):(b))
#define  max(a,b)       ((a)>(b)? (a):(b))

#define  SX         3       /* screen width */
#define  FOV        10      /* field of view (in degree) */
#define  FOV_H      deg2rad(FOV)

static const double ANGLE_PER_PIXEL = FOV_H / (SX-1.);
static const double FOVH_2 = FOV_H / 2.0;

enum { VERT, HORIZ };

typedef enum { false=0, true=1 } bool;
typedef enum { DIR_N=0, DIR_E, DIR_W, DIR_S } dir_t;

#define  MAPX   6
#define  MAPY   5

static int map[MAPX][MAPY] = {  /* warning: index order is [x][y] */
    {1,1,1,1,1}, /* [0][*] */
    {1,0,0,0,1}, /* [1][*] */
    {1,0,0,0,1}, /* [2][*] */
    {1,1,0,0,1}, /* and so on... */
    {1,1,0,0,1},
    {1,1,1,1,1}
};

int
map_get_cell( int x, int y )
{
    return (x >= 0 && x < MAPX && y >= 0 && y < MAPY) ? map[x][y] : -1;
}

int
sgn( double d )
{
    return is_zero(d) ? 0 : ((d > 0) ? 1 : -1);
}

double
l2dist( double x0, double y0, double x1, double y1 )
{
    double dx = x0 - x1;
    double dy = y0 - y1;
    return sqrt(dx*dx + dy*dy);
}

bool
get_wall_intersection( double ray, double px, double py, dir_t* wdir, double* wx, double* wy )
{
    int xstep = sgn( cos(ray) );  /* +1 (right), 0 (no change), -1 (left) */
    int ystep = sgn( sin(ray) );  /* +1 (up),    0 (no change), -1 (down) */

    double xslope = (xstep == 0) ? INFINITY : tan(ray);
    double yslope = (ystep == 0) ? INFINITY : 1./tan(ray);

    double nx = (xstep > 0) ? floor(px)+1 : ((xstep < 0) ? ceil(px)-1 : px);
    double ny = (ystep > 0) ? floor(py)+1 : ((ystep < 0) ? ceil(py)-1 : py);

    printf("\nray=%.2f deg, xstep=%d, ystep=%d, xslope=%.2f, yslope=%.2f, nx=%.2f, ny=%.2f\n",
        rad2deg(ray), xstep, ystep, xslope, yslope, nx, ny);

    double f=INFINITY, g=INFINITY;
    bool hit = false;
    int hit_side; /* either VERT or HORIZ */

    while( !hit )
    {
        int mapx, mapy;

        if( xstep != 0 ) f = xslope * (nx-px) + py;
        if( ystep != 0 ) g = yslope * (ny-py) + px;

        /* which is nearer to me - VERT(nx,f) or HORIZ(g,ny)? */
        double dist_v = l2dist(px, py, nx, f);
        double dist_h = l2dist(px, py, g, ny);

        if( dist_v < dist_h ) { /* VERT is nearer; go along x-axis */
            mapx = (xstep == 1) ? (int)(nx) : (int)(nx)-1 ;
            mapy = (int) f;
            hit_side = VERT;
            printf(" V(%d, %.2f) ->", mapx, f);
        }
        else {  /* HORIZ is nearer; go along y-axis */
            mapx = (int) g;
            mapy = (ystep == 1) ? (int)(ny) : (int)(ny)-1 ;
            hit_side = HORIZ;
            printf(" H(%.2f, %d) ->", g, mapy);
        }
        int cell = map_get_cell(mapx, mapy);
        if( cell < 0 ) break;   /* out of map */

        if( cell == 1 ) {   /* hit wall? */
            if( hit_side == VERT ) {
                *wdir = (xstep > 0) ? DIR_W : DIR_E;
                *wx = nx;
                *wy = f;
            }
            else { /* HORIZ */
                *wdir = (ystep > 0) ? DIR_S : DIR_N;
                *wx = g;
                *wy = ny;
            }
            hit = true;
            printf(" hit wall!\n");
            break;
        }

        if( hit_side == VERT ) nx += xstep;
        else ny += ystep;
    }
    /* end of while(!hit) */

    return hit;
}

double
cast_single_ray( int x, double px, double py, double th )
{
    double ray = (th + FOVH_2) - (x * ANGLE_PER_PIXEL);

    dir_t wdir;     /* direction of wall */
    double wx, wy;  /* coord. of wall intersection point */

    if( get_wall_intersection(ray, px, py, &wdir, &wx, &wy) == false )
        return INFINITY; /* no intersection - maybe bad map? */

    double wdist = l2dist(px, py, wx, wy);

    return wdist;
}

int
main( int ac, char** av )
{
    if( ac != 4 ) {
        fprintf(stderr,"usage: %s x y th(deg)\n", av[0]);
        exit(1);
    }
    double px, py, th;
    px = atof(av[1]);
    py = atof(av[2]);
    th = deg2rad(atof(av[3]));

    /* print map */
    for( int y=MAPY-1; y>=0; y-- ) {
        for( int x=0; x<MAPX; x++ ) {
            printf("%c ", (map_get_cell(x,y)==1 ? '#':'.'));
        }
        putchar('\n');
    }

    for( int x=0; x<SX; x++ ) {
        double wdist = cast_single_ray(x, px, py, th);
        printf("** ray %3d : dist %.2f\n", x, wdist);
    }

    return 0;
}