function numberToWords(num) {
    if (num === 0) return "Zero";

    const belowTwenty = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                         "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"];
    const tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"];
    const thousands = ["", "Thousand", "Million", "Billion"];

    function helper(num) {
        if (num === 0) return "";
        else if (num < 20) return belowTwenty[num] + " ";
        else if (num < 100) return tens[Math.floor(num / 10)] + " " + helper(num % 10);
        else return belowTwenty[Math.floor(num / 100)] + " Hundred " + helper(num % 100);
    }

    let word = "";
    for (let i = 0, unit = 1000; num > 0; i++, num = Math.floor(num / 1000)) {
        if (num % 1000 !== 0) {
            word = helper(num % 1000) + thousands[i] + " " + word;
        }
    }

    return word.trim();
}

// Examples
console.log(numberToWords(123));        // "One Hundred Twenty Three"
console.log(numberToWords(12345));      // "Twelve Thousand Three Hundred Forty Five"
console.log(numberToWords(1234567));    // "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

