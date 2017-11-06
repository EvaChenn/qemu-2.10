/*
 * Arm PrimeCell PL061 General Purpose IO with additional
 * Luminary Micro Stellaris bits.
 *
 * Copyright (c) 2007 CodeSourcery.
 * Written by Paul Brook
 *
 * This code is licensed under the GPL.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "qemu/log.h"


#define TYPE_EVA "eva"
#define eva(obj) OBJECT_CHECK(evastate, (obj), TYPE_EVA)

typedef struct evastate {
    SysBusDevice parent_obj;

    MemoryRegion iomem;
	qemu_irq irq;
} evastate;

int i = 0;

static char eva_read(void *opaque, hwaddr offset,
                           unsigned size)
{
    	printf("test read\n");
	char test[20] = "test eva read!!!";
	i++;
    	return test[i];
}

static void eva_write(void *opaque, hwaddr offset,
                        uint64_t value, unsigned size)
{
     printf("test write\n");
    qemu_log_mask(LOG_GUEST_ERROR,
                  "pl061_write: Bad offset %x\n", (int)offset);
}



static const MemoryRegionOps eva_ops = {
    .read = eva_read,
    .write = eva_write,
    .endianness = DEVICE_NATIVE_ENDIAN,
};



static void eva_init(Object *obj)
{
    evastate *s = eva(obj);
    DeviceState *dev = DEVICE(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);


    memory_region_init_io(&s->iomem, obj, &eva_ops, s, "eva", 0x1000);
    sysbus_init_mmio(sbd, &s->iomem);

}

static void eva_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
	printf("eva~~~~~~~test\n");
	i=0;

}

static const TypeInfo eva_info = {
    .name          = TYPE_EVA,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(evastate),
    .instance_init = eva_init,
    .class_init    = eva_class_init,
};


static void eva_register_types(void)
{
    type_register_static(&eva_info);
   
}

type_init(eva_register_types)
