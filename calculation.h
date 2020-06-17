float avgHw(float hw1, float hw2, float hw3){
	float result = (hw1 + hw2 + hw3) / 3;
	return result;	
}
float avgEx(float ex1, float ex2, float ex3){
	float result = (ex1 + ex2 + ex3) / 3;
	return result;	
}
float totalScore(float hw, float ex, float mid, float final){	//Function to calculate total score
	float result = (0.15 * hw) + (0.15 * ex) + (0.3 * mid) + (0.4 * final);
	return result;
}
