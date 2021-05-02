#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <unistd.h> 
#include <math.h>


const int FPS = 20;
const int map_height = 16;
const int map_width  = 16;

const int screen_width = 100; 
const int screen_height = 40;

char *screen;


char *map = "################"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"#..............#"
			"################";


float player_angle = 0.0f; 
float FOV          = 3.14159f;
float depth        = 16.0f;

float player_x     = 14.7f;
float player_y     = 5.00f;


void screen_init(char *s)
{

}



int main(void) 
{
	screen = malloc(sizeof(char) * screen_height * screen_width);
	screen_init(screen);

	while (true) {

		for (int x = 0; x < screen_width; ++x) {
			float ray_angle = (player_angle - FOV / 2.0f) + ((float)x / (float)screen_width) * FOV;

			float step_size = 0.1f;
			float distance_to_wall = 0.0f;

			float eye_x = sinf(ray_angle);
			float eye_y = sinf(ray_angle);
		
			bool hit_wall = false; 


			while (!hit_wall && distance_to_wall < depth) {
				distance_to_wall += step_size; 
				int test_x = (int)(player_x + eye_y * distance_to_wall);
				int test_y = (int)(player_y + eye_y * distance_to_wall);


				if (test_x < 0 || test_x >= map_width || test_y < 0 || test_y >= map_height) {
					hit_wall = true;
					distance_to_wall = depth;
				}
				else {
					if (map[test_x * map_width + test_y] == '#') {
						hit_wall = true;
					}
				}

			}
			

		}

		//update
		system("clear"); usleep(1000000 / FPS);
	}

	free(screen);

	return 0;
}


