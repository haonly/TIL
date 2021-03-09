package main

import (
	"fmt"
	"math"
)

type geometry interface{
	area() float32
	volume() float32
}

type Cylinder struct{
	r, h float32
}

type Cuboid struct{
	a, b, c float32
}

func (cy Cylinder) area() float32{
	return ((math.Pi*cy.r*cy.r)*2 + (2*math.Pi*cy.r*cy.h))
}

func (cy Cylinder) volume() float32{
	return (math.Pi*cy.r*cy.r)*cy.h
}

func (cu Cuboid) area() float32{
	return 2*cu.a*cu.b + 2*cu.a*cu.c + 2*cu.b*cu.c
}

func (cu Cuboid) volume() float32{
	return cu.a*cu.b*cu.c
}

func main() {
	cy1 := Cylinder{10, 10}
	cy2 := Cylinder{4.2, 15.6}
	cu1 := Cuboid{10.5, 20.2, 20}
	cu2 := Cuboid{4, 10, 23}
	
	printMeasure(cy1, cy2, cu1, cu2)	
}

func printMeasure(m ...geometry) {
	for _, val := range m{
		fmt.Printf("%.2f, %.2f\n", val.area(), val.volume())
		
	}
}