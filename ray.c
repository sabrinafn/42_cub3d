#include <stdio.h>
#include <math.h>

#define WORLD_SIZE 10

int main() {
    char world_map[WORLD_SIZE][WORLD_SIZE] = {
        {"##########"},
        {"#........#"},
        {"#........#"},
        {"#.#.####.#"},
        {"#........#"},
        {"#..#######"},
        {"#........#"},
        {"#........#"},
        {"#........#"},
        {"##########"}
    };

	// posição do player/camera
    double camera_x = 8.5;
    double camera_y = 2.5;

	// direção x e y de pra onde está olhando
    double ray_dir_x = 1.0;
    double ray_dir_y = 1.0;

	// teorema de pitagoras para pegar a distancia de um pro outro
	double ray_len = sqrt(ray_dir_x * ray_dir_x + ray_dir_y * ray_dir_y);

	// calculo do meio entre o X e o Y
    ray_dir_x /= ray_len;
    ray_dir_y /= ray_len;

    double ray_x = camera_x;
    double ray_y = camera_y;

    int map_x = (int)ray_x;
    int map_y = (int)ray_y;

    double delta_dist_x = fabs(1.0 / ray_dir_x);
    double delta_dist_y = fabs(1.0 / ray_dir_y);

    double side_dist_x = delta_dist_x * (map_x + 1 - ray_x);
    double side_dist_y = delta_dist_y * (map_y + 1 - ray_y);

    int step_x = (ray_dir_x < 0) ? -1 : 1;
    int step_y = (ray_dir_y < 0) ? -1 : 1;

	int player_x = (int)camera_x;
	int player_y = (int)camera_y;

    int hit = 0;
    while (!hit) {
        if (side_dist_x < side_dist_y) {
            side_dist_x += delta_dist_x;
            map_x += step_x;
        } else {
            side_dist_y += delta_dist_y;
            map_y += step_y;
        }

        if (world_map[map_y][map_x] == '#') {
            printf("Hit wall at (%d, %d)\n", map_x, map_y);
            world_map[map_y][map_x] = '@'; // Mark the hit cell
            hit = 1;
        }

        if (map_x < 0 || map_x >= WORLD_SIZE || map_y < 0 || map_y >= WORLD_SIZE) {
            printf("Ray out of bounds.\n");
            hit = 1;
        }
    }
	world_map[player_y][player_x] = 'P';
    // Print the modified map:
    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            printf("%c", world_map[y][x]);
        }
        printf("\n");
    }

    return 0;
}
