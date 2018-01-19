#include <kernel/atag.h>

uint32_t get_mem_size(atag_t * tag) {
   while (tag->tag != NONE) {
       if (tag->tag == MEM) {
           return tag->mem.size;
       }
       tag = (atag_t *)(((uint32_t *)tag) + tag->tag_size);
   }

   // 1<<27 = 128mb
   // we will play it safe by only saying 1/4th of that, which is still 32mb
   return 1<<24;

}
