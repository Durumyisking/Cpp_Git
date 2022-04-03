#include "pch.h"





/*

	r * 3.14 = 둘레의 절반

	라디안 : 반지름과 호의 길이와의 실질적인 비율값

	우리는 파이를 각도로 볼거임

	3.14 라디안 = 180도

	라디안이 1일때 호의 길이 = 반지름



	cos = 밑변 / 빗변으로, 빗변이 1일때 밑변이 어느정도인지 비율
	나머지는 그대로

	cos0 = 1	cos90 = 0	cos180 = -1 
	sin0 = 0	sin90 = 1	sin180 = 0


	우리가 직선으로 100을 가려면 1프레임마다 100 * DT씩 이동해서 100에 도달 이때 1초 걸림
	우리가 45도 방향으로 100을 가고싶다 칠때 45도 방향으로 100을 그은 후 그때 좌표의 x, y를 구해서 피타고라스 정리로 구해얗마
	그때의 x는 100cos45		y는 100sin45
	d

*/
	


/*
	project 흐름

	***obj delete***
	1frame
	update		: 
	finalupdate	: 2. oncollision enter
	collision	: 1. 콜리전 발생
	render		: 4. obj set dead, 5. deadvec.pushback(obj)
	event		: 3. Delete event

	2frame
	update		: 
	finalupdate	: 
	collision	: 
	render		: 6. dead상태인 obj scene내에서 erase
	event		: 7. 등록해놓은 deadvec 비우기

*/