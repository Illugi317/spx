#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../include/png.h"

struct start_chunk{
    uint32_t length; // 4
    uint32_t chunk_type; // 4
};

int loading_loop()
{
    FILE *ppng = fopen("test.png","r"); // open the fucking bitch
    //Read the fucking magic
    uint8_t magic[8] = {0};
    size_t read_size = fread(&magic, 8, 1, ppng);
    if(memcmp(magic, PNG_MAGIC, 8) != 0)
    {
        printf("Image Magic not correct for PNG!\n");
        return -1;
    };
    printf("Magic check correct\n");
    int IEND_detected = 0;
    // IHDR Beginning
    // IDAT Data stuffs
    // IEND Stop reading
    ihdr_header_chunk ihdr = {0};
    /*
     * Current pointer is now at +8. First is IHDR, Switch case on chunk type
     */
    while(IEND_detected != 1)
    {
        struct start_chunk start = {0};
        size_t read_bytes = fread(&start, sizeof(start), 1, ppng);
        start.length = be32toh(start.length);
        start.chunk_type = be32toh(start.chunk_type);
        // Length
        // Chunk type
        switch(start.chunk_type){
            case IHDR_CHUNK_TYPE:
                // Load the fucker
                read_bytes = fread(&ihdr, sizeof(ihdr), 1, ppng);
                ihdr.width = be32toh(ihdr.width);
                ihdr.height = be32toh(ihdr.height);
                ihdr.b_depth = be32toh(ihdr.b_depth);
                ihdr.color_type = be32toh(ihdr.color_type);
                ihdr.compression_method = be32toh(ihdr.compression_method);
                ihdr.filter_method = be32toh(ihdr.filter_method);
                ihdr.interlace_method = be32toh(ihdr.interlace_method);
                ihdr.crc_check = be32toh(ihdr.crc_check);
                printf("ihdr width: %d\n",ihdr.width);
                printf("ihdr height: %d\n",ihdr.height);
                printf("ihdr b_depth: %x\n",ihdr.b_depth);
                printf("ihdr color_type: %x\n",ihdr.color_type);
                printf("ihdr compression_method: %x\n",ihdr.compression_method);
                printf("ihdr filter_method: %x\n",ihdr.filter_method);
                printf("ihdr interlace_method: %x\n",ihdr.interlace_method);
                printf("ihdr crc_check %x\n",ihdr.crc_check);
                if (read_bytes != 1){
                    //Mismatch
                    return -1;
                }
                continue;

            case IDAT_CHUNK_TYPE:
                /*
                 * Alloc into heap, memcopy over to heap and move pointer
                 */
                continue;

            case PLTE_CHUNK_TYPE:
                continue;

            case IEND_CHUNK_TYPE:
                IEND_detected = 1;
                continue;

            default:
                continue;
        }
    }
}

int test(){
    int blablabal = loading_loop();
    printf("Testing png call\n");
    //unsigned char buffer[50];
    /*
    ihdr_header_chunk hdr = {0};

    memset(&hdr, 0, sizeof(hdr));

    FILE *ppng = fopen("test.png","r");

    fseek(ppng, 8, SEEK_SET);

    size_t read_size = fread(&hdr, sizeof(hdr), 1, ppng);

    hdr.length = be32toh(hdr.length);

    hdr.chunk_type = be32toh(hdr.chunk_type);

    printf("Length %d & Chunk Type %d\n", hdr.length, hdr.chunk_type);
    printf("Width %d\n", be32toh(hdr.width));
    printf("Height %d\n",be32toh(hdr.height));
    */
    // first 8 bytes in PNG always: 137 80 78 71 13 10 26 10
    return 0;
}
