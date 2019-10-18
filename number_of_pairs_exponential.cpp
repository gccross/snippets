#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    size_t T;
	cin >> T;
	while (T--) {
	    size_t M,N, res=0;
	 
	    cin >> M >> N;
	    unsigned int X[M], Y[N];
	    for (size_t i = 0; i< M; ++i) cin >> X[i];
	    for (size_t i = 0; i< N; ++i) cin >> Y[i];

		sort(X,X+M);
        sort(Y,Y+N);

		for (unsigned * i = upper_bound(X, X+M, 1); i<X+M; ++i) {
			unsigned* j = upper_bound(Y, Y+N, *i); 
			res+=distance(j,Y+N);			
	
		}

		// y=1
		unsigned dx = distance(upper_bound(X, X+N, 1), X+M);
		unsigned dy = distance(lower_bound(Y, Y+M, 1), upper_bound(Y, Y+M, 1));
		res += dx*dy;

		// x=2, y=3
		pair<unsigned*, unsigned*> p = equal_range(X, X+M, 2);
		dx = distance(p.first, p.second);
		p = equal_range(Y, Y+N, 3);
		dy = distance(p.first, p.second);
		res-=dx*dy;

		// x=2, y=4
		pair<unsigned*, unsigned*> p = equal_range(X, X+M, 2);
		dx = distance(p.first, p.second);
		p = equal_range(Y, Y+N, 4);
		dy = distance(p.first, p.second);
		res-=dx*dy;

		// x=3, y=2
		pair<unsigned*, unsigned*> p = equal_range(X, X+M, 3);
		dx = distance(p.first, p.second);
		p = equal_range(Y, Y+N, 2);
		dy = distance(p.first, p.second);
		res+=dx*dy;

	

	    cout << res << endl;
	}
	return 0;
}
//	
//	Given two arrays X and Y of positive integers, find number of pairs such that x^y > y^x (raised to power of) where x is an element from X and y is an element from Y.
//	
//	Input:
//	The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test consists of three lines. The first line of each test case consists of two space separated M and N denoting size of arrays X and Y respectively. The second line of each test case contains M space separated integers denoting the elements of array X. The third line of each test case contains N space separated integers denoting elements of array Y.
//	
//	Output:
//	Corresponding to each test case, print in a new line, the number of pairs such that xy > yx.
//	
//	Constraints:
//	1 ≤ T ≤ 100
//	1 ≤ M, N ≤ 105
//	1 ≤ X[i], Y[i] ≤ 103
//	
//	Example:
//	Input
//	1
//	3 2
//	2 1 6
//	1 5
//	
//	Output
//	3
//	
//	Explanation:
//	Testcase 1: The pairs which follow xy > yx are as such: 21 > 12,  25 > 52 and 61 > 16 
//	
//	1
//	151 90
//	339 464 136 198 210 131 225 409 238 475 421 373 294 356 235 62 57 107 185 76 383 120 242 433 185 280 280 284 168 337 126 119 238 29 120 78 238 92 57 296 61 402 294 433 137 81 376 408 185 75 220 291 477 42 352 330 291 475 73 92 190 288 491 240 394 54 64 182 404 6 177 480 196 140 469 499 84 140 16 122 494 327 223 339 329 82 400 479 392 24 444 335 244 350 203 208 3 142 188 347 392 138 414 401 317 191 163 436 127 411 378 383 261 190 206 375 164 223 196 67 361 39 89 312 246 468 426 368 190 43 64 48 3 118 100 24 227 204 49 52 71 137 459 468 457 406 32 463 320 476 57
//	32 496 45 92 304 389 416 451 320 273 292 384 134 276 143 70 301 455 79 86 258 334 394 491 104 251 234 223 272 112 491 339 142 259 48 353 159 480 303 184 491 3 69 423 396 136 9 362 243 195 200 189 179 43 358 442 348 470 346 381 414 465 211 62 386 74 5 463 204 103 70 155 30 53 75 150 231 245 345 50 119 66 364 53 274 471 232 248 12 370
//	
// correct output: 6767
//	
//	1
//	3 2
//	2 1 6
//	1 5
//
// correct output: 3
//
//	1
//	163 191
//	429 125 482 490 426 485 287 36 497 163 364 36 168 438 156 76 155 471 164 461 264 317 95 148 19 10 165 113 25 435 307 382 91 135 416 363 81 420 27 371 351 445 19 217 62 423 7 327 204 40 311 215 252 433 486 185 302 36 3 464 65 13 441 212 38 279 282 335 52 41 211 39 8 350 452 351 107 296 172 122 89 176 226 308 129 266 287 374 290 186 482 156 188 395 7 217 92 152 288 243 183 472 53 96 222 302 388 228 326 141 92 331 458 52 305 173 22 18 356 24 252 79 399 387 389 322 12 101 29 10 323 79 460 454 60 369 42 118 461 254 151 87 308 27 250 274 465 326 271 396 423 447 247 32 71 311 269 309 260 71 454 305 257
//	455 4 2 144 120 235 345 329 494 192 341 458 18 466 373 32 207 89 456 46 155 324 19 188 97 408 452 423 305 191 382 411 299 118 445 13 415 165 155 94 60 158 387 480 116 57 41 283 340 328 67 83 432 91 214 232 105 185 159 5 249 159 84 53 499 8 154 475 23 186 185 42 256 440 254 177 404 304 435 283 332 247 371 256 65 411 181 361 279 228 383 111 88 231 343 204 454 218 313 171 216 172 230 207 2.................
//	

