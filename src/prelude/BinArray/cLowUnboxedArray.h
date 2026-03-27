/* cLowUnboxedArray.h */
/*     stuff for stateful unboxed arrays */

struct UnboxedArray {
  int free;
  int write;
  unsigned end;
  unsigned *block;
};

typedef struct UnboxedArray *UBA;
extern void finaliseUBA (UBA);

#ifndef __BYTE_ORDER__
#error "Could not determine target endianness"
#endif

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#if !defined(htonl)
#define htonl(x) x
#define ntohl(x) x
#endif
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#if !defined(htonl)
extern unsigned htonl(unsigned);
extern unsigned ntohl(unsigned);
#endif
#endif

#if __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
#if !defined(htonl)
#error "TODO: Not implemented"
#endif
#endif
