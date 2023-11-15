#include "nuclei.h"
#include "nuclei_misc.h"

/*  MISC RESET   */
int32_t misc_reset_enable_core()
{
    
    MISC_CTL->SYSRESET |= MISC_ENABLE_CORE;
    return 0;
}

int32_t misc_reset_get_por_cause()
{
    
    return MISC_CTL->SYSRESET & MISC_POR_CAUSE;
}

int32_t misc_reset_get_nsys_rst_cause()
{
    
    return MISC_CTL->SYSRESET & MISC_NSYS_RST_CAUSE;
}

int32_t misc_reset_get_core_cause()
{
    
    return MISC_CTL->SYSRESET & MISC_CORE_CAUSE;
}


/*  NMI   */

int32_t misc_nmi_get_ext_pending()
{
    
    return MISC_CTL->NMI & MISC_NMI_EXT_PENDING;
}


/* CACHE SYSTEM CONTROL */


int32_t misc_dcache_flush_inv(MISC_DCACHE DCACHE_OP)
{
     MISC_CTL->CATCHE_CTL & DCACHE_OP;
     return 0;
}

int32_t misc_dcache_flush_inv_pending(MISC_DCACHE DCACHE_OP)
{
     return MISC_CTL->CATCHE_CTL & DCACHE_FLUASH_INVPENDINH;
}

int32_t misc_icache_invalidate()
{
     MISC_CTL->CATCHE_CTL |= ICACHE_INVALIDATE;
     return 0;
}

int32_t misc_icache_inv_pending()
{
     return MISC_CTL->CATCHE_CTL &= ICACHE_INVPENDINH; 
}


/* clock control*/

int32_t misc_clock_sel_ocs()
{
     MISC_CTL->CLOCK_CTL  &= ~(CLOCK_SEL_OCS);
     return 0;
}

int32_t misc_clock_sel_divide()
{
     MISC_CTL->CLOCK_CTL  |= (CLOCK_SEL_OCS);
     return 0;
}

int32_t misc_set_clock_divide(int32_t clock_divide)
{
     MISC_CTL->CLOCK_CTL  &= ~CLOCK_SEL_DIVIDE;
     MISC_CTL->CLOCK_CTL  |= (clock_divide<<CLOCK_SEL_DIVIDE_OFS)& CLOCK_SEL_DIVIDE;
     return 0;
}

int32_t misc_get_clock_divide()
{
     return (MISC_CTL->CLOCK_CTL  & CLOCK_SEL_DIVIDE)>>1;
}


int32_t misc_ppi_clock_divide(int32_t ppi_clock_divide)
{
     MISC_CTL->CLOCK_CTL  &= ~CLOCK_PPI_DIVIDE;
     MISC_CTL->CLOCK_CTL  |= (ppi_clock_divide<<CLOCK_PPI_DIVIDE_OFS)& CLOCK_PPI_DIVIDE;
     return 0;
}


