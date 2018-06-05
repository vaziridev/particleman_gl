/*Omid Vaziri*/
/*040-704-985*/
/*vaziri_particle.c*/

#include "vaziri_particle.h"

/*Sets default values, so each particle
 *starts off at (0,0) and move to the right
 *at a speed of 1.0*/
int particle_init(struct particle* p){
	static int init = 0;
	if(init == 0){
		srand(time(NULL));
		init = 1;
	}
	p -> col.r = rand() % 10;
	p -> col.r /= 10;
	p -> col.g = rand() % 10;
	p -> col.g /= 10;
	p -> col.b = rand() % 10;
	p -> col.b /= 10;
	p -> col.a = 1.0;
	p -> pos.x = 0.0;
	p -> pos.y = 0.0;
	p -> pos.z = 0.0;
	p -> dir.x = 1.0;
	p -> dir.y = 0.0;
	p -> dir.z = 0.0;
	p -> spd.x = 1.0;
	p -> spd.y = 0.0;
	p -> spd.z = 0.0;
	p -> lifespan = 0;
	p -> size = 12.0;

	return 0;
}/*end particle_init*/

/*My particle add is altered so that I could
 *actually draw out the pac-man and 4 "points"
 *and any extra particles added after the picture
 *(which requires 123 particles to display) are
 *placed so they overlap the very first particle*/
int particle_add(struct particle **head){
        //static variables required for drawing pacman  
	static int colcount = -50;
	static int rowcount = 0;
	static int check = 0;
	//particle to be added to linked list
	struct particle *newParticle;
	newParticle = (struct particle*)malloc(sizeof(struct particle));
	//initialize particle with default values
	particle_init(newParticle);

	//determine where the new particle should go
	switch(rowcount){
		case 0:
			if(check == 0){
				colcount = -50;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 7*4;
			if(colcount == -50 + (4*5)){
				rowcount++;
				check = 0;
			}
			break;
		case 1:
			if(check == 0){
				colcount = -58;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 6*4;
			if(colcount == -58 + 4*9){
				rowcount++;
				check = 0;
			}
			break;
		case 2:
			if(check == 0){
				colcount = -62;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 5*4;
			if(colcount == -62 + 4*11){
				rowcount++;
				check = 0;
			}
			break;
		case 3:
			if(check == 0){
				colcount = -62;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 4*4;
			if(colcount == -62 + 4*11){
				rowcount++;
				check = 0;
			}
			break;
		case 4:
			if(check == 0){
				colcount = -66;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 4*3;
			if(colcount == -66 + 4*10){
				rowcount++;
				check = 0;
			}
			break;
		case 5:
			if(check == 0){
				colcount = -66;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 4*2;
			if(colcount == -66 + 4*8){
				rowcount++;
				check = 0;
			}
			break;
		case 6:
			if(check == 0){
				colcount = -66;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += 4;
			if(colcount == -66 + 4*6){
				rowcount++;
				check = 0;
			}
			break;
		case 7:
			if(check == 0){
				colcount = -66;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			if(colcount == -66 + 4*6){
				rowcount++;
				check = 0;
			}
			break;
		case 8:
			if(check == 0){
				colcount = -66;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += -4;
			if(colcount == -66 + 4*8){
				rowcount++;
				check = 0;
			}
			break;
		case 9:
			if(check == 0){
				colcount = -66;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += -4*2;
			if(colcount == -66 + 4*10){
				rowcount++;
				check = 0;
			}
			break;
		case 10:
			if(check == 0){
				colcount = -62;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += -4*3;
			if(colcount == -62 + 4*11){
				rowcount++;
				check = 0;
			}
			break;
		case 11:
			if(check == 0){
				colcount = -62;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += -4*4;
			if(colcount == -62 + 4*11){
				rowcount++;
				check = 0;
			}
			break;
		case 12:
			if(check == 0){
				colcount = -58;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += -4*5;
			if(colcount == -58 + 4*9){
				rowcount++;
				check = 0;
			}
			break;
		case 13:
			if(check == 0){
				colcount = -50;
				check = 1;
			}
			newParticle -> pos.x += colcount;
			colcount += 4;
			newParticle -> pos.y += -4*6;
			if(colcount == -50 + 5*4){
				rowcount++;
				check = 0;
			}
			break;
		case 14:
			newParticle->pos.x = 0;
			newParticle->pos.y += 2;
			rowcount++;
			break;
		case 15:
			newParticle->pos.x = 20;
			newParticle->pos.y += 2;
			rowcount++;
			break;
		case 16:
			newParticle->pos.x = 40;
			newParticle->pos.y += 2;
			rowcount++;
			break;
		case 17:
			newParticle->pos.x = 60;
			newParticle->pos.y += 2;
			rowcount++;
			break;
		case 18:
			newParticle->pos.x = -50;
			newParticle->pos.y = 28;
			break;
		default:
			printf("Error\n");
			return -1;
	}
	//Add particle to linked list
	newParticle -> next = *head;
	*head = newParticle;

	return 0;
}/*end particle_add*/

/*Free allocated memory*/
int particle_remove(struct particle* p){
	free(p);
	return 0;
}/*end particle_remove*/

/*Kill them all*/
int particle_destroy(struct particle **head){
	struct particle *del = NULL;
	struct particle *curr;
	curr = *head;

	while(curr -> next != NULL){
		del = curr;
		curr = curr -> next;
		particle_remove(del);
	}
	particle_remove(curr);
	return 0;
}/*end particle_destroy*/

/*Updates particles to move 'pacman'*/
int particle_update(struct particle **head){
	struct particle *curr;
	static int glowcount = 0; //Variable used to make the 'food' fade in/out
	static float increment = -0.05;
	int i;
	//Iterate through list, shifting each particle to the right
	curr = *head;
	for(i = 0; i < DFLT_INIT_NUM_PARTICLES - 124; i++){
		curr->pos.x = curr->pos.x + (curr->spd.x * curr->dir.x);
		curr = curr->next;
	}
	//Make the food glow!
	glowcount++;
	for(i = 0; i < 4; i++){
		if(glowcount == 20){
			increment = increment * (-1);
			glowcount = 0;
		}
		curr->col.a = curr->col.a + increment;
		if(curr->pos.x == 100){
			curr->pos.x = -100;
		}
		else{
			curr->pos.x = curr->pos.x + (curr->spd.x * curr->dir.x);
		}
		curr = curr->next;
	}
	//Reposition particles to left border upon reaching right border
	while(curr != NULL){
		if(curr->pos.x == 100){
			curr->pos.x = -100;
		}
		else{
			curr->pos.x = curr->pos.x + (curr->spd.x * curr->dir.x);
		}
		curr = curr->next;
	}
	return 0;
}/*end particle_update*/
