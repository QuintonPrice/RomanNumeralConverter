# CPTR 141: Project #1

## Problem Overview
In 1937 Claude Shannon of Petoskey, MI wrote the seminal work for computing that showed how
Boolean logic could be expressed in electronic circuits leading to computers as we know them. For
fun he created Throbac (THrifty ROman-numerical BAckward-looking Computer), a calculator that
did arithmetic with Roman numerals (pictured above)—a useless, but whimsical device. In this
project, you will write a program that performs addition with Roman numerals, just like Throbac.

|   |
|:-:|
|![THROBAC](./throbac.jpg)|

Roman numerals have values, but are not positional like our number system, and there is no zero (zero arrived in the west circa 1000 AD). To keep things simpler, we will use five of the seven symbols: 
| Symbol | I | V | X | L | C |
|:------:|:-:|:-:|:-:|:-:|:-:|
|Value         |1|5|10|50|100|
Numbers are formed by combining symbols together and adding their values—only whole numbers.  For example, `CLXVII` is 100+50+10+5+1+1 = 167. Generally, symbols are placed in order of value, starting with the largest values. When smaller values precede larger values, the smaller values are subtracted from the larger values, and the result is added to the total. For example, in `XLIV` the smaller `X` before `L` means subtract `X` from `L` as 50-10 to get 40, and the `I` before `V` means subtract `I` from `V` as 5-1 to get 4, so the final number is 44. Some call that the “subtraction rule.” A useful restriction of the subtraction rule is that there can never be more than one smaller value. That is, `XL` is valid, but `XXL` is not: thirty is represented by `XXX`.  The table below shows the base values up to three hundered.  To keep this program simpler, we will assume that our values will stay less than 380.  See [Wikipedia](https://en.wikipedia.org/wiki/Roman_numerals) for more details. 

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|Times One| `I` | `II` | `III` | `IV` | `V` | `VI` | `VII` | `VIII` | `IX` |
|Times Ten| `X`|`XX`|`XXX`|`XL`|`L`|`LX`|`LXX`|`LXXX`|`XC`|
|Times a Hundred|`C`|`CC`|`CCC`|||||||

Your program must do the following:

1. Prompt the user for two Roman Numerals.
2. Convert both numerals into integers.
3. Find the sum of those two integers.
4. Convert the sum back into Roman Numerals and print the result.

## Solution Specification
Your solution should strive to meet the standards specified below as they form the basis on which it will be graded.

1. Your program must prompt the user for two Roman Numerals in some easy-to-follow fashion and perform appropriate validation checks on the user input.  For example, you should check to be sure only valid characters for Roman Numerals are entered.
2. Your program must find the integer value of each Roman Numeral.  Here are a few hints to get you started in developing your algorithm for this:
    * First, play with Roman numerals with pencil and paper to get familiar with how they work -- 
      especially conversion to and from integers. Notice how the “subtraction rule” requires you to
      look at pairs of symbols. The restriction that only one smaller value can precede a larger value
      will be quite helpful in developing your algorithm.
    * Simplify! Inside of every problem is a simpler one.  For example, 
      * The most obvious simplification is to handle the four steps in your program individually—You might even decide to start just converting from roman numerals to an integer as a separate program while developing your solution.
      * You may wish to try solving the problem first for Roman Numerals that don't use the subtraction rule.  Once you have that working, you can come back and add code to handle subtraction.
    * It is okay to have a large number of `if-else-if` statements.  There are many different cases that you will need to handle, so don't get concerned if you have 20 or more of these in your program.
3. After your program computes the integer sum of the two converted Roman Numerals, you must translate it back into Roman Numerals correctly.  So if the user enters `IV` and `V` your program should return `IX`, not `IVV` or `IIIIIIIII`.
4. You should handle user interaction gracefully.  That is, if a user does something unexpected, give them a chance to fix it.  Once a single computation has been done, ask if they'd like to do another. 
5. Since this is a project, you have a lot of freedom in how you choose to accomplish the task.  However, you are expected to make use of the following concepts somewhere in your program.

    * Appropriately named variables
    * C++ computation (addition, multiplication, division, etc.)
    * Branching statements (``if``, ``if-else``, ``if-else-if``, and/or ``switch``)
    * Looping statements (``while``, ``do-while``, and/or ``for``)
    * Well-formatted code including appropriate comments.

## Code Review and Grading
Before you can turn in your project, you must participate in a [code review](https://en.wikipedia.org/wiki/Code_review) with your TA or with a tutor at the Student Development Center.  This [walk-through](https://en.wikipedia.org/wiki/) style review is a guided-tour of your source code in which you describe how you implemented the various features, explain why you made the choices you did, and solicit constructive input which might help improve your final product.  

You must bring a filled-out and signed code review form to your instructor before your project can be graded.  Ideally, you should complete the code review after you've finished most of the project, but before the due date (so that you have time to make changes based on the feedback you get).

<style>
  #grade td, #grade th {
    padding: 2px;
    border: 1px solid black;
  }
</style>
<table id="grade" cellspacing="0">
  <tr>
    <th style="width: 5%"></th>
    <th style="width: 23.75%">Algorithm</th>
    <th style="width: 23.75%">User Interaction</th>
    <th style="width: 23.75%">Use of Required Concepts</th>
    <th style="width: 23.75%">Coding Style</th>
  </tr>
  <tr>
    <th>E</th>
    <td>Performs correctly for all allowed Roman Numeral inputs</td>
    <td>Excellently formatted output and handles input errors well</td>
    <td>All required concepts included</td>
    <td>Code is well commented and readable</td>
  </tr>
  <tr>
    <th>M</th>
    <td>Works correctly for allowed Roman Numerals that don't use subtraction</td>
    <td>Good formatting and handles most input errors</td>
    <td>Most required concepts included</td>
    <td>Code is sparsely commented or over-commented and may have some formatting issues,  but is mostly readable</td>
  </tr>
  <tr>
    <th>R</th>
    <td>An attempt to implement the algorithm was made, but was not successful</td>
    <td>Basic user interaction with little or no input validation</td>
    <td>Some required concepts were used, but a good number are not</td>
    <td>Comments are sparse or non-existent and the code is very hard to follow</td>
  </tr>
  <tr>
    <th>N</th>
    <td>No attempt at implementing the algorithm is evident</td>
    <td>No user interaction or input validation</td>
    <td>Only one or two required concepts were included</td>
    <td>Comments are lacking and/or code is unreadable</td>
  </tr>
</table>