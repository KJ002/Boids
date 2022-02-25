#include "raylib.h"
#include "stdlib.h"
#include "math.h"

#define FPS 60
#define WIDTH 800
#define HEIGHT 450
#define TITLE "Boids Example"

typedef struct Boid {
	float rotation;
	Vector2* positions;
} Boid;

Boid* newBoid(){
	Vector2* positions = malloc(sizeof(Vector2)*3);

	positions[0] = (Vector2){0.0f, 50.0f};
	positions[1] = (Vector2){25.0f, 0.0f};
	positions[2] = (Vector2){-25.0f, 0.0f};

	Boid* boid = malloc(sizeof(Boid));
	*boid = (Boid){0, positions};

	return boid;
}

void drawBoid(Boid* boid, Vector2 center){
	Vector2 screenPositions[3] = {boid->positions[0], boid->positions[1], boid->positions[2]};

	for (int i = 0; i < 3; i++) {
		screenPositions[i] = (Vector2){screenPositions[i].x+center.x, screenPositions[i].y+center.y};
	}

	DrawTriangle(screenPositions[0], screenPositions[1], screenPositions[2], BLUE);
}

int main(void){
	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(FPS);

	Boid* boid = newBoid();

	while (!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);
		drawBoid(boid, (Vector2){400, 1});
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
