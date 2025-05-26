#include "so_long.h"

static bool
check_flood(char **copy, t_game *game, char target)
{
    int y;
    int x;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (copy[y][x])
        {
            if (copy[y][x] == target)
            {
                free_map(copy);
                return (false);
            }
            x++;
        }
        y++;
    }
    free_map(copy);
    return (true);
}

static bool check_collectibles_access(t_game *game)
{
    char **copy;
    t_dim dim;
    t_coord start;

    dim = (t_dim){game->width, game->height};
    start = (t_coord){game->player_x, game->player_y};
    copy = duplicate_map(game->map, game->height);
    flood_fill_collect(copy, dim, start);
    return (check_flood(copy, game, COLLECTIBLE));
}

static bool check_exit_access(t_game *game)
{
    char **copy;
    t_dim dim;
    t_coord start;

    dim = (t_dim){game->width, game->height};
    start = (t_coord){game->player_x, game->player_y};
    copy = duplicate_map(game->map, game->height);
    flood_fill_exit(copy, dim, start);
    return (check_flood(copy, game, EXIT));
}

bool validate_map(t_game *game)
{
    t_counter cnt;
    int y;

    cnt = (t_counter){0, 0, 0};
    y = 0;
    while (y < game->height)
    {
        if ((int)ft_strlen(game->map[y]) != game->width || !check_line(game, y, &cnt))
            return (false);
        y++;
    }
    if (!check_elements_count(&cnt))
        return (false);
    game->collectibles = cnt.c;
    return (check_collectibles_access(game) && check_exit_access(game));
}

bool check_elements_count(t_counter *cnt)
{
    if (cnt->p == 1 && cnt->c >= 1 && cnt->e == 1)
        return (true);
    return (false);
}