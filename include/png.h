
#include <stdint.h>

static const uint8_t PNG_MAGIC[8] = {0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A};

typedef struct __attribute__((packed)) ihdr_header_chunk{
    int width;
    int height;
    uint8_t b_depth;
    uint8_t color_type;
    uint8_t compression_method;
    uint8_t filter_method;
    uint8_t interlace_method;
    uint32_t crc_check;
} ihdr_header_chunk;

#define TAG_NAME(a,b,c,d) ((uint32_t)(a<<24)|(b<<16)|(c<<8)|(d))

#define IHDR_CHUNK_TYPE TAG_NAME('I','H','D','R')
#define IDAT_CHUNK_TYPE TAG_NAME('I','D','A','T')
#define IEND_CHUNK_TYPE TAG_NAME('I','E','N','D')
#define PLTE_CHUNK_TYPE TAG_NAME('P', 'L','T','E')

int test();
int loading_loop();
