# Challenge #287
# Assumptions: all inputs are 4-digits or less

# Return num as an array of its digits
def num_array(num)
    arr = Array.new
    
    until num <= 0
        arr.push(num % 10)
        num = num / 10
    end

    until arr.length == 4
        arr.push(0)
    end
    arr
end


# Find Largest Digit
def largest_digit(num)
    array = num_array num
    index = 0
    max_index = 0

    until index == array.length
        if array[index] > array[max_index]
            max_index = index
        end
        index = index + 1
    end

    array[max_index]
end

# Descending sort
def desc_digits(num)
    descending = num_array(num).sort.reverse
    return descending.join.to_i
end

# Ascending sort
def asce_digits(num)
    ascending = num_array(num).sort
    return ascending.join.to_i 
end

# Find number of iterations in Kaprekar's Routine
# Assumptions: input is 4 unique digits
def kaprekar(num)
    kaprekars_constant = 6174
    iterations = 0

    until num == kaprekars_constant
        num = (desc_digits(num) - asce_digits(num))
        iterations = iterations + 1
    end
    iterations
end



# Test Cases

#Challenge
puts largest_digit 1234
puts largest_digit 3253
puts largest_digit 9800
puts largest_digit 3333
puts largest_digit 120

#Bonus 1
puts desc_digits 1234
puts desc_digits 3253
puts desc_digits 9800
puts desc_digits 3333
puts desc_digits 120

#Bonus 2

puts kaprekar 6589
puts kaprekar 5455
puts kaprekar 6174
