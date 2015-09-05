#ifndef _BITOPS_H
#define _BITOPS_H

#define CLEAR_BIT(N, BIT) \ 
		(N) = (N) & ~(1 << BIT)
#define SET_BIT(N, BIT) \
		(N) = (N) | (1 << BIT)
#define TOGGLE_BIT(N, BIT) \
		(N) = (N) ^ (1 << BIT)
#endif
