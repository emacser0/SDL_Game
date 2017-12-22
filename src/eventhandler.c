#include "include/handle.h"
#include "include/print.h"

int
__handleevent(SDL_Event * event) {
    __printlog("---EVENT---\n");
    __printtime(event, &timer, t);
    switch (event->type) {
    case SDL_KEYUP:
    case SDL_KEYDOWN:
	__handlekey(event, &(event->key));
	break;
    case SDL_QUIT:
	__printquit(event);
	__printlog("---EVENT---\n");
	__handlequit(event);
	break;
    default:
	__printlog("undefined event\n");
	__printlog("---EVENT---\n");
	return 1;
    }
    __printlog("---EVENT---\n");
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
__handlekeysym(SDL_Event * __attribute((unused)) event,
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