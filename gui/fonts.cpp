const pm_uchar font_5x7[] PROGMEM = {
#include "fonts/std/font_05x07_avr.lbm"
#if defined(TRANSLATIONS_DE)
#include "fonts/std/font_de_05x07.lbm"
#elif defined(TRANSLATIONS_CZ)
#include "fonts/std/font_cz_05x07.lbm"
#elif defined(TRANSLATIONS_ES)
#include "fonts/std/font_es_05x07.lbm"
#elif defined(TRANSLATIONS_FI)
#include "fonts/std/font_fi_05x07.lbm"
#elif defined(TRANSLATIONS_FR)
#include "fonts/std/font_fr_05x07.lbm"
#elif defined(TRANSLATIONS_IT)
#include "fonts/std/font_it_05x07.lbm"
#elif defined(TRANSLATIONS_PL)
#include "fonts/std/font_pl_05x07.lbm"
#elif defined(TRANSLATIONS_PT)
#include "fonts/std/font_pt_05x07.lbm"
#elif defined(TRANSLATIONS_SE)
#include "fonts/std/font_se_05x07.lbm"
#endif
};

#if defined(BOLD_SPECIFIC_FONT)
  const pm_uchar font_5x7_B[] PROGMEM = {
  #include "fonts/std/font_05x07_B_compressed.lbm"
  };
#endif

#if !defined(BOOT)
const pm_uchar font_10x14[] PROGMEM = {
#include "fonts/std/font_10x14_compressed.lbm"

};
#endif

