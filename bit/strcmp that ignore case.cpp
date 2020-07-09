Following are the detailed steps.
1) Iterate through every character of both strings and do following for each character.
…a) If str1[i] is same as str2[i], then continue.
…b) If inverting the 6th least significant bit of str1[i] makes it same as str2[i], then continue. For example, if str1[i] is 65, then inverting the 6th bit will make it 97. And if str1[i] is 97, then inverting the 6th bit will make it 65.
…c) If any of the above two conditions is not true, then break.
2) Compare the last (or first mismatching in case of not same) characters.

int ic_strcmp(string s1, string s2)
{
    int i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
        /* If characters are same or inverting the
        6th bit makes them same */
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
        continue;
        else
        break;
    }

    /* Compare the last (or first mismatching in
    case of not same) characters */
    if (s1[i] == s2[i])
        return 0;

    // Set the 6th bit in both, then compare
    if ((s1[i] | 32) < (s2[i] | 32))
        return -1;
    return 1;
    -----------------------------------------------------------------------------------------------

    xor without xor opertaor

1) Find bitwise OR of x and y (Result has set bits where either x has set or y has set bit). OR of x = 3 (011) and y = 5 (101) is 7 (111)

2) To remove extra set bits find places where both x and y have set bits. The value of expression “~x | ~y” has 0 bits wherever x and y both have set bits.

3) bitwise AND of “(x | y)” and “~x | ~y” produces the required result.

Below is implementation.


