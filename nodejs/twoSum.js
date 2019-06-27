/*
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/
const TwoSum = (numbers, target) => {
    const Maper = {};
    for(let index = 0; index < numbers.length; ++index) {
        const current = numbers[index];
        const need = target-current;
        if(Maper[need]!== undefined) {
            return [Maper[need], index];
        } else {
            Maper[current] = index;
        }
    }
}

console.log(TwoSum([2,7,6,5,12,4], 19))