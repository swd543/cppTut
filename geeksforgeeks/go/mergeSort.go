package main

import "fmt"

func main() {
	a := []int{9, 4, 1, 5, 3, 0, 6, 8, 3, 5}
	//a := []int{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
	fmt.Printf("Hello! %v\n", a)
	fmt.Printf("Hello! %v\n", mergesort(a))
}

func mergesort(a []int) []int {
	length := len(a)
	if length <= 1 {
		return a
	}
	fmt.Printf("%v\n", a)
	l := mergesort(a[0 : length/2])
	r := mergesort(a[length/2 : length])
	return merge(l, r)
}

func merge(l []int, r []int) []int {
	i := 0
	j := 0
	size := len(l) + len(r)
	a := make([]int, size)
	k := 0
	for ; i < len(l) && j < len(r); k++ {
		if l[i] > r[j] {
			a[k] = r[j]
			j++
		} else {
			a[k] = l[i]
			i++
		}
	}
	for ; i < len(l); i++ {
		a[k] = l[i]
		k++
	}
	for ; j < len(r); j++ {
		a[k] = r[j]
		k++
	}
	return a
}
