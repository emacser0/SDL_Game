#include "include/handle.h"
#include "include/print.h"

int
__inithandler() {
    flags.running=1;
    flags.update=1;
    return 0;
}

int
__handleevent(SDL_Event * event) {
    __printstart(event);
    switch (event->type) {
    case SDL_KEYUP:
    case SDL_KEYDOWN:
	__handlekey(event, &(event->key));
	break;
    case SDL_QUIT:
	__printquit(event);
	__handlequit(event);
	break;
    default:
	__printend(event);
    }
    __printend(event);
    return 0;
}

int
__handlequit(SDL_Event * __attribute__ ((unused)) event) {
    flags.running = 0;
    __printquit(event);
    return 0;
}

int
__handlekey(SDL_Event * __attribute__ ((unused)) event,
	    SDL_KeyboardEvent * key) {
    switch (key->type) {
    case SDL_KEYUP:
	__printlog("KEYUP\n");
	break;
    case SDL_KEYDOWN:
	__printlog("KEYDOWN\n");
	break;
    default:
	return 1;
    }
    __handlekeysym(event, &(key->keysym));
    return 0;
}

int
__handlekeysym(SDL_Event * __attribute__ ((unused)) event,
	       SDL_Keysym * keysym) {
    __printkeysym(event, keysym);
    switch (keysym->sym) {
    case SDLK_ESCAPE:
	__handlequit(event);
	break;
    case SDLK_1:
	break;
    default:
	return 1;
    }
    return 0;
}
