#undef TAPPING_TERM
#define TAPPING_TERM 170

// If a key is pressed and released while the mod-tap key is down then we
// consider a hold even if we are still below the tapping term. This makes it
// possible to have a longer tapping term but a responsive experience.
#define PERMISSIVE_HOLD

// Only bilateral combinations count for mod-tap unless they are held for
// longer than 400 ms. Avoids missfires of mod on rolls
#define BILATERAL_COMBINATIONS 400
