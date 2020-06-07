#if !defined(BOOT)
const pm_char s_charTab[] PROGMEM = "_-.,";

char hex2zchar(uint8_t hex)
{
  return (hex >= 10 ? hex-9 : 27+hex);
}

char idx2char(int8_t idx)
{
  if (idx == 0) return ' ';
  if (idx < 0) {
    if (idx > -27) return 'a' - idx - 1;
    idx = -idx;
  }
  if (idx < 27) return 'A' + idx - 1;
  if (idx < 37) return '0' + idx - 27;
  if (idx <= 40) return pgm_read_byte(s_charTab+idx-37);
#if LEN_SPECIAL_CHARS > 0
  if (idx <= (LEN_STD_CHARS + LEN_SPECIAL_CHARS)) return 'z' + 5 + idx - 40;
#endif
  return ' ';
}

#endif

#if defined(COLORLCD)
char *strAppendDigits(char *dest, int value)
{
  div_t qr = div(value, 10);
  *dest++ = '0' + qr.quot;
  *dest++ = '0' + qr.rem;
  *dest = '\0';
  return dest;
}
#endif

#if defined(CPUARM) || defined(SDCARD)
char *strAppend(char *dest, const char *source, int len)
{
  while ((*dest++ = *source++)) {
    if (--len == 0) {
      *dest = '\0';
      return dest;
    }
  }
  return dest - 1;
}

char *strSetCursor(char *dest, int position)
{
  *dest++ = 0x1F;
  *dest++ = position;
  *dest = '\0';
  return dest;
}

char *strAppendFilename(char *dest, const char *filename, const int size)
{
  memset(dest, 0, size);
  for (int i=0; i<size; i++) {
    char c = *filename++;
    if (c == '\0' || c == '.')
      break;
    *dest++ = c;
  }
  return dest;
}

#define LEN_FILE_EXTENSION 4
char *getFileExtension(char *filename, int size)
{
  int len = min<int>(size, strlen(filename));
  for (int i=len; i>=len-LEN_FILE_EXTENSION; --i) {
    if (filename[i] == '.') {
      return &filename[i];
    }
  }
  return NULL;
}

#if defined(RTCLOCK)
#include "rtc.h"

char * strAppendDate(char * str, bool time)
{
  str[0] = '-';
  struct gtm utm;
  gettime(&utm);
  div_t qr = div(utm.tm_year+1900, 10);
  str[4] = '0' + qr.rem;
  qr = div(qr.quot, 10);
  str[3] = '0' + qr.rem;
  qr = div(qr.quot, 10);
  str[2] = '0' + qr.rem;
  str[1] = '0' + qr.quot;
  str[5] = '-';
  qr = div(utm.tm_mon+1, 10);
  str[7] = '0' + qr.rem;
  str[6] = '0' + qr.quot;
  str[8] = '-';
  qr = div(utm.tm_mday, 10);
  str[10] = '0' + qr.rem;
  str[9] = '0' + qr.quot;

  if (time) {
    str[11] = '-';
    div_t qr = div(utm.tm_hour, 10);
    str[13] = '0' + qr.rem;
    str[12] = '0' + qr.quot;
    qr = div(utm.tm_min, 10);
    str[15] = '0' + qr.rem;
    str[14] = '0' + qr.quot;
    qr = div(utm.tm_sec, 10);
    str[17] = '0' + qr.rem;
    str[16] = '0' + qr.quot;
    str[18] = '\0';
    return &str[18];
  }
  else {
    str[11] = '\0';
    return &str[11];
  }
}
#endif
#endif
