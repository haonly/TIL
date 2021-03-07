package main

import "fmt"

var g float32 = 9.8

type energyStruct struct {
  m float32
  v float32
	h float32
	ke float32
	pe float32
	me float32
}

func (energy energyStruct) kinEnergy() (ke float32) {
	return energy.m * energy.v * energy.v/2
} 

func (energy energyStruct) potEnergy() (pe float32) {
	return energy.m * g * energy.h
}

func main() {
	var num int
	
	fmt.Scanln(&num)	

	energy_slice := make([]energyStruct, num)


	for i := 0; i < num; i++ {	
		fmt.Scanln(&energy_slice[i].m, &energy_slice[i].v, &energy_slice[i].h)
		energy_slice[i].ke = energy_slice[i].kinEnergy()
		energy_slice[i].pe = energy_slice[i].potEnergy()
		energy_slice[i].me = energy_slice[i].ke + energy_slice[i].pe
	}
	
	for i := 0; i < num; i++ {
		fmt.Println(energy_slice[i].ke, energy_slice[i].pe, energy_slice[i].me)
	}
	
}

