/*************************************************************************
	> File Name: light.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2022年03月16日 星期三 00时25分07秒
 ************************************************************************/
#define Vtop Vconv_cal

#include<iostream>
// #include<nvboard.h>
//#include<Vlight.h>
#include<Vconv_cal.h>
#include<verilated.h>
#include<verilated_vcd_c.h>
#include<bitset>
using namespace std;

#define word_t uint64_t
#define paddr_t uint64_t
#define CONFIG_MBASE 0x80000000
#define CONFIG_MSIZE 0x8000000
#define CONFIG_PC_RESET_OFFSET 0x0
#define RESET_VECTOR (CONFIG_MBASE + CONFIG_PC_RESET_OFFSET)
#define PG_ALIGN __attribute((aligned(4096)))

static uint8_t pmem[CONFIG_MSIZE] ;
static inline word_t host_read(void *addr, int len) {
	
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    case 8: return *(uint64_t *)addr;
    default: return 0;
  }
}

// void nvboard_bind_all_pins(Vtop *top);
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }
const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
VerilatedVcdC* tfp = NULL;
double sc_time_stamp() {return 0;}

static word_t pmem_read(paddr_t addr, int len) {

  word_t ret = host_read(guest_to_host(addr), len);

  return ret;
}
static const uint32_t img [] = {
//   0x00000297,  // auipc t0,0
//   0x7DEA02B7,//lui 
//  // 0xFFF28FE7,//jalr

//   0x0002b823,  // sd  zero,16(t0)
//   0x0102b503,  // ld  a0,16(t0)
	0x1E078C13,//addi
	0x7E078C13,//addi
	0x8E0C0C13,//addi
	0xaE0C0C13,
	0xbE0C0C13,
	0xFE0C0C13,
	0x4E0C0C13,
	0x7E0C0C13,
  	0x00100073  // ebreak (used as nemu_trap)
//   0xdeadbeef,  // some data
};
template <class T>
void step_and_dump_wave(T *top){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}
template<class T>
void sim_init(T * top) {
	tfp = new VerilatedVcdC;
	contextp->debug(0);
	contextp->randReset(2);
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("dump.vcd");	
}
template<class T>
void single_cycle(T * top) {
	top->clock = 1; top->eval();step_and_dump_wave(top);
	top->clock = 0; top->eval();step_and_dump_wave(top);
}

template<class T>
void reset(T *top , int n) {
	top->reset = 1;
	while(n -- > 0) single_cycle(top);
	top->reset = 0;
}

int main(int argc,char ** argv,char** env) {
	memset(pmem,0,sizeof(pmem));
	if(false && argc && argv && env) {}
	memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
	Verilated::mkdir("logs");
    Vtop * top = new Vtop;
	sim_init(top);
	// nvboard_bind_all_pins(top);
	// nvboard_init();
	reset(top,10);
	step_and_dump_wave(top);


	while(1){
	    
	//step_and_dump_wave(top);

	// nvboard_update();

   }


	tfp->close();

}


