#include <stdio.h>

// #define FLEN 3
// #define NGOLD 2

typedef struct {
	int player; // indeks/pozicija igraca
	// int carry; // ima li igrac zlato
	int kupus;
	int ovca;
	int vuk;
	// int field[FLEN];
} State;

State new_game() {
	State s;
	// s.carry = 0;
	s.player = 0;
	s.kupus = 0;
	s.ovca = 0;
	s.vuk = 0;
	// for (int i = 0; i < FLEN; i++)
	// 	s.field[i] = 0;
	// s.field[FLEN - 1] = NGOLD;
	return s;
}

void print_state(State *s) {
	printf("----------------------------------\n");
	// printf("vuk %d, ovca %d, kupus %d, farmer %d\n", s->vuk, s->ovca, s->kupus, s->player);
	if(!s->vuk)
		printf("VUK\n");
	if(s->vuk)
		printf("\t\t\t VUK\n");
	if(!s->ovca)
		printf("OVCA\n");
	if(s->ovca)
		printf("\t\t\t OVCA\n");
	if(!s->kupus)
		printf("KUPUS\n");
	if(s->kupus)
		printf("\t\t\t KUPUS\n");
	if(!s->player)
		printf("FARMER\n");
	if(s->player)
		printf("\t\t\t FARMER\n");
}

int next_states(State *s, State *nstates) {
	int ns = 0;
	//uzmi ovcu i odnesi je
	if(s->player == s->ovca) {
		nstates[ns] = *s;
		nstates[ns].player = !s->player;
		nstates[ns].ovca = !s->ovca;
		nstates[ns].kupus = s->kupus;
		nstates[ns].vuk = s->vuk;
		ns++;
	}
	//uzmi vuka i odesni ga
	if(s->player == s->vuk) {
		nstates[ns].player = !s->player;
		nstates[ns].vuk = !s->vuk;
		nstates[ns].ovca = s->ovca;
		nstates[ns].kupus = s->kupus;
		ns++;
	}
	//uzmi kupus i odnesi ga
	if(s->player == s->kupus) {
		nstates[ns].player = !s->player;
		nstates[ns].kupus = !s->kupus;
		nstates[ns].ovca = s->ovca;
		nstates[ns].vuk = s->vuk;
		ns++;
	}
	//pomakni farmera na suprotnu stranu
	nstates[ns].player = !s->player;
	nstates[ns].vuk = s->vuk;
	nstates[ns].ovca = s->ovca;
	nstates[ns].kupus = s->kupus;
	ns++;
	return ns;
}

int goal_state(State *s) {
	//ako su svi na drugoj strani tj imaju vrijednost 1
	return s->ovca && s->vuk && s->kupus && s->player;
}

int valid(State *s) {
	//ako su ovca i kupus bez farmera ili vuk i ovca bez farmera
	if((s->ovca == s->vuk && s->ovca != s->player) || (s->ovca == s->kupus && s->kupus != s->player))
		return 0;
	return 1;
}

int solve(State *s, int d) {
	if (d == 0)
		return 0;
	if(!valid(s))
		return 0;
	if (goal_state(s)) {
		print_state(s);
		return 1;
	}
	State nstates[4];
	int ns = next_states(s, nstates);
	for (int i = 0; i < ns; i++) {
		if (solve(&nstates[i], d - 1)) {
			print_state(s);
			return 1;
		}
	}
	return 0;
}

int main() {
	State s = new_game();
	int solved = 0;
	for(int d=1; d < 20; d++)
		if (solve(&s, d)) {
			solved = d;
			break;
		}
	if(solved > 0) {
		printf("solved in %d\n", solved);
	} else {
		printf("not solved\n");
	}
	return 0;
}
