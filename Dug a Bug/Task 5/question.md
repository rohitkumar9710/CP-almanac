### Question
You are given a string consisting of only digits and a character, `-`.

Any substring mentioned in that string is called a date if it is strictly in the format `dd-mm-yyyy`. The number of the date's occurrences is the number of such substrings in that string. For example, the string "7214-11-2014-11-2014" mentions date 14-12-2014 twice (first time as "72<i>14-11-2014</i>-11-2014", second time as "7214-11-20<i>14-11-2014</i>").

Find the date occuring in the string having maximum occurences. 

#### Note:
A date is valid only if the year lies in the range from 2013 to 2015, the month is from 1 to 12, and the number of the day is strictly lying in the range of the number of days in the current month. Note that a date is written in the format `dd-mm-yyyy`, that means that leading zeroes may be added to the numbers of the months or days if needed. In other words, date "2-2-2013" isn't recorded in the format "dd-mm-yyyy", and date "02-02-2013" is recorded in it.

And the string length is not exceeding 10<sup>5</sup>.