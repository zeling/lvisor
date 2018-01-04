#include <asm/init.h>
#include <asm/processor.h>
#include <asm/setup.h>
#include <sys/console.h>

noreturn void main(unsigned int magic, struct multiboot_info *multiboot_info)
{
        /* enable output first */
        porte9_init(BRIGHT_YELLOW);
        vgacon_init();

        cpu_init();

        /* require cpu */
        tsc_init();

        /* require cpu */
        trap_init();

        multiboot_init(magic, multiboot_info);

        acpi_table_init();

        /* require acpi */
        apic_init();

        /* require multiboot */
        kvm_init();

        kvm_bsp_run();
}
