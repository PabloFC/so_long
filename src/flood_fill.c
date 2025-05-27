#include "so_long.h"

void flood_fill_collect(char **map, t_dim dim, t_coord pt)
{
    if (pt.x < 0 || pt.x >= dim.w || pt.y < 0 || pt.y >= dim.h)
        return;
    if (map[pt.y][pt.x] == '1' || map[pt.y][pt.x] == 'V' || map[pt.y][pt.x] == 'E')
        return;
    map[pt.y][pt.x] = 'V';
    flood_fill_collect(map, dim, (t_coord){pt.x + 1, pt.y});
    flood_fill_collect(map, dim, (t_coord){pt.x - 1, pt.y});
    flood_fill_collect(map, dim, (t_coord){pt.x, pt.y + 1});
    flood_fill_collect(map, dim, (t_coord){pt.x, pt.y - 1});
}

void flood_fill_exit(char **map, t_dim dim, t_coord pt)
{
    if (pt.x < 0 || pt.x >= dim.w || pt.y < 0 || pt.y >= dim.h)
        return;
    if (map[pt.y][pt.x] == '1' || map[pt.y][pt.x] == 'V')
        return;
    if (map[pt.y][pt.x] == 'E')
    {
        map[pt.y][pt.x] = 'V';
        return;
    }
    map[pt.y][pt.x] = 'V';
    flood_fill_exit(map, dim, (t_coord){pt.x + 1, pt.y});
    flood_fill_exit(map, dim, (t_coord){pt.x - 1, pt.y});
    flood_fill_exit(map, dim, (t_coord){pt.x, pt.y + 1});
    flood_fill_exit(map, dim, (t_coord){pt.x, pt.y - 1});
}
