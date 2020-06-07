#ifndef _DUMP_H_
#define _DUMP_H_

void dumpStart(unsigned int size);
void dumpBody(const uint8_t * data, unsigned int size);
void dumpEnd();
void dump(const uint8_t * data, unsigned int size);


#endif // _DUMP_H_
