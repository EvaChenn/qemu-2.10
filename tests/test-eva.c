//#include "qemu/osdep.h"
//#include "libqtest.h"


#include "qemu/osdep.h"

#include "qemu-common.h"
#include "qemu/cutils.h"
#include "libqtest.h"
#include "qapi/qmp/types.h"

int main(int argc, char **argv){

	g_test_init(&argc,&argv, NULL);
	qtest_start("-device eva");
	int ret = g_test_run();
	qtest_end();
	return ret;
}

