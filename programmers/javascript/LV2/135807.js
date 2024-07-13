function gcd(a, b) {
    while (b !== 0) {
        let r = a % b;
        a = b;
        b = r;
    }
    return a;
}

function solution(arrayA, arrayB) {
    let answer = 0, gcdA = arrayA[0], gcdB = arrayB[0];

    for (let i = 1; i < arrayA.length; i++) {
        gcdA = gcd(Math.max(gcdA, arrayA[i]), Math.min(gcdA, arrayA[i]));
        gcdB = gcd(Math.max(gcdB, arrayB[i]), Math.min(gcdB, arrayB[i]));
    }

    let flagA = false, flagB = false;

    for (let i = 0; i < arrayA.length; i++) {
        if (flagA && flagB) {
            break;
        }
        if (!flagA && arrayB[i] % gcdA === 0) {
            flagA = true;
        }
        if (!flagB && arrayA[i] % gcdB === 0) {
            flagB = true;
        }
    }

    return flagA ? (flagB ? 0 : gcdB) : (flagB ? gcdA : Math.max(gcdA, gcdB));
}

const arrayA = [10, 17];
const arrayB = [5, 20];

const answer = solution(arrayA, arrayB);
console.log(`answer = ${answer}`);