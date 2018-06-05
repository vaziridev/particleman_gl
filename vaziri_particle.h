/*header file for vaziri_particle.c*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DFLT_INIT_NUM_PARTICLES	127

typedef struct col{
	float r;
	float g;
	float b;
	float a;
}Color4;

typedef struct vector{
	float x;
	float y;
	float z;
}Point3D, Vector3D;

struct particle{
	Color4				col;
	Point3D				pos;
	Vector3D			dir;
	Vector3D			spd;
	int				lifespan;
	int				size;
	struct particle*	        next;
};

int particle_init(struct particle* p);
int particle_add(struct particle **head);
int particle_remove(struct particle *p);
int particle_destroy(struct particle **head);
int particle_update(struct particle **head);
