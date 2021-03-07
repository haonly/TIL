package main

import "fmt"

type student struct {
	name string
	sex string
	score map[string]int
}

// 생성자 함수
func newStruct(name, sex string) *student{
	std := student{}
	std.name = name
	std.sex = sex
	std.score = map[string]int{} // score 필드의 맵을 초기화
	return &std 
}

func main() {
	var student_num int
	var subject_num int
	var name string
	var sex string
	var subject_name string
	var subject_score int
	
	fmt.Scanln(&student_num, &subject_num)
	
	slice_student := make([]*student, 0, 0) 
	
	for i:=0; i<student_num; i++{	
		fmt.Scanln(&name, &sex)
		slice_student = append(slice_student, newStruct(name, sex))
		
		for j := 0; j < subject_num; j++{
			fmt.Scanln(&subject_name, &subject_score)
			slice_student[i].score[subject_name] = subject_score
			
		}
	}
		
	
	for i := 0; i < student_num; i++{
		fmt.Println("----------")
		fmt.Println(slice_student[i].name, slice_student[i].sex)
		
		for index, val := range slice_student[i].score {
			fmt.Println(index, val)
		}
		
	}
	fmt.Println("----------")
}