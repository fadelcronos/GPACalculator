char grades(float *totScore, char *grades)
{
    if (*totScore >= 85.0)
        *grades = 'A';
    else if (*totScore >= 70.0 && *totScore < 85.0)
        *grades = 'B';
    else if (*totScore >= 60.0 && *totScore < 70.0)
        *grades = 'C';
    else if (*totScore >= 55.0 && *totScore < 60.0)
        *grades = 'D';
    else if (*totScore < 55.0)
        *grades = 'E';
}
