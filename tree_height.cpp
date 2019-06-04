// Calculate the height of a binary tree. 
// Tree containes no duplicate elements.
/* Input.  Save in a file and redirect stdin

3
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R
510
0 1 L 0 2 R  1 3 L 1 4 R  2 5 L 2 6 R  3 7 L 3 8 R  4 9 L 4 10 R  5 11 L 5 12 R  6 13 L 6 14 R  7 15 L 7 16 R  8 17 L 8 18 R  9 19 L 9 20 R  10 21 L 10 22 R  11 23 L 11 24 R  12 25 L 12 26 R  13 27 L 13 28 R  14 29 L 14 30 R  15 31 L 15 32 R  16 33 L 16 34 R  17 35 L 17 36 R  18 37 L 18 38 R  19 39 L 19 40 R  20 41 L 20 42 R  21 43 L 21 44 R  22 45 L 22 46 R  23 47 L 23 48 R  24 49 L 24 50 R  25 51 L 25 52 R  26 53 L 26 54 R  27 55 L 27 56 R  28 57 L 28 58 R  29 59 L 29 60 R  30 61 L 30 62 R  31 63 L 31 64 R  32 65 L 32 66 R  33 67 L 33 68 R  34 69 L 34 70 R  35 71 L 35 72 R  36 73 L 36 74 R  37 75 L 37 76 R  38 77 L 38 78 R  39 79 L 39 80 R  40 81 L 40 82 R  41 83 L 41 84 R  42 85 L 42 86 R  43 87 L 43 88 R  44 89 L 44 90 R  45 91 L 45 92 R  46 93 L 46 94 R  47 95 L 47 96 R  48 97 L 48 98 R  49 99 L 49 100 R  50 101 L 50 102 R  51 103 L 51 104 R  52 105 L 52 106 R  53 107 L 53 108 R  54 109 L 54 110 R  55 111 L 55 112 R  56 113 L 56 114 R  57 115 L 57 116 R  58 117 L 58 118 R  59 119 L 59 120 R  60 121 L 60 122 R  61 123 L 61 124 R  62 125 L 62 126 R  63 127 L 63 128 R  64 129 L 64 130 R  65 131 L 65 132 R  66 133 L 66 134 R  67 135 L 67 136 R  68 137 L 68 138 R  69 139 L 69 140 R  70 141 L 70 142 R  71 143 L 71 144 R  72 145 L 72 146 R  73 147 L 73 148 R  74 149 L 74 150 R  75 151 L 75 152 R  76 153 L 76 154 R  77 155 L 77 156 R  78 157 L 78 158 R  79 159 L 79 160 R  80 161 L 80 162 R  81 163 L 81 164 R  82 165 L 82 166 R  83 167 L 83 168 R  84 169 L 84 170 R  85 171 L 85 172 R  86 173 L 86 174 R  87 175 L 87 176 R  88 177 L 88 178 R  89 179 L 89 180 R  90 181 L 90 182 R  91 183 L 91 184 R  92 185 L 92 186 R  93 187 L 93 188 R  94 189 L 94 190 R  95 191 L 95 192 R  96 193 L 96 194 R  97 195 L 97 196 R  98 197 L 98 198 R  99 199 L 99 200 R  100 201 L 100 202 R  101 203 L 101 204 R  102 205 L 102 206 R  103 207 L 103 208 R  104 209 L 104 210 R  105 211 L 105 212 R  106 213 L 106 214 R  107 215 L 107 216 R  108 217 L 108 218 R  109 219 L 109 220 R  110 221 L 110 222 R  111 223 L 111 224 R  112 225 L 112 226 R  113 227 L 113 228 R  114 229 L 114 230 R  115 231 L 115 232 R  116 233 L 116 234 R  117 235 L 117 236 R  118 237 L 118 238 R  119 239 L 119 240 R  120 241 L 120 242 R  121 243 L 121 244 R  122 245 L 122 246 R  123 247 L 123 248 R  124 249 L 124 250 R  125 251 L 125 252 R  126 253 L 126 254 R  127 255 L 127 256 R  128 257 L 128 258 R  129 259 L 129 260 R  130 261 L 130 262 R  131 263 L 131 264 R  132 265 L 132 266 R  133 267 L 133 268 R  134 269 L 134 270 R  135 271 L 135 272 R  136 273 L 136 274 R  137 275 L 137 276 R  138 277 L 138 278 R  139 279 L 139 280 R  140 281 L 140 282 R  141 283 L 141 284 R  142 285 L 142 286 R  143 287 L 143 288 R  144 289 L 144 290 R  145 291 L 145 292 R  146 293 L 146 294 R  147 295 L 147 296 R  148 297 L 148 298 R  149 299 L 149 300 R  150 301 L 150 302 R  151 303 L 151 304 R  152 305 L 152 306 R  153 307 L 153 308 R  154 309 L 154 310 R  155 311 L 155 312 R  156 313 L 156 314 R  157 315 L 157 316 R  158 317 L 158 318 R  159 319 L 159 320 R  160 321 L 160 322 R  161 323 L 161 324 R  162 325 L 162 326 R  163 327 L 163 328 R  164 329 L 164 330 R  165 331 L 165 332 R  166 333 L 166 334 R  167 335 L 167 336 R  168 337 L 168 338 R  169 339 L 169 340 R  170 341 L 170 342 R  171 343 L 171 344 R  172 345 L 172 346 R  173 347 L 173 348 R  174 349 L 174 350 R  175 351 L 175 352 R  176 353 L 176 354 R  177 355 L 177 356 R  178 357 L 178 358 R  179 359 L 179 360 R  180 361 L 180 362 R  181 363 L 181 364 R  182 365 L 182 366 R  183 367 L 183 368 R  184 369 L 184 370 R  185 371 L 185 372 R  186 373 L 186 374 R  187 375 L 187 376 R  188 377 L 188 378 R  189 379 L 189 380 R  190 381 L 190 382 R  191 383 L 191 384 R  192 385 L 192 386 R  193 387 L 193 388 R  194 389 L 194 390 R  195 391 L 195 392 R  196 393 L 196 394 R  197 395 L 197 396 R  198 397 L 198 398 R  199 399 L 199 400 R  200 401 L 200 402 R  201 403 L 201 404 R  202 405 L 202 406 R  203 407 L 203 408 R  204 409 L 204 410 R  205 411 L 205 412 R  206 413 L 206 414 R  207 415 L 207 416 R  208 417 L 208 418 R  209 419 L 209 420 R  210 421 L 210 422 R  211 423 L 211 424 R  212 425 L 212 426 R  213 427 L 213 428 R  214 429 L 214 430 R  215 431 L 215 432 R  216 433 L 216 434 R  217 435 L 217 436 R  218 437 L 218 438 R  219 439 L 219 440 R  220 441 L 220 442 R  221 443 L 221 444 R  222 445 L 222 446 R  223 447 L 223 448 R  224 449 L 224 450 R  225 451 L 225 452 R  226 453 L 226 454 R  227 455 L 227 456 R  228 457 L 228 458 R  229 459 L 229 460 R  230 461 L 230 462 R  231 463 L 231 464 R  232 465 L 232 466 R  233 467 L 233 468 R  234 469 L 234 470 R  235 471 L 235 472 R  236 473 L 236 474 R  237 475 L 237 476 R  238 477 L 238 478 R  239 479 L 239 480 R  240 481 L 240 482 R  241 483 L 241 484 R  242 485 L 242 486 R  243 487 L 243 488 R  244 489 L 244 490 R  245 491 L 245 492 R  246 493 L 246 494 R  247 495 L 247 496 R  248 497 L 248 498 R  249 499 L 249 500 R  250 501 L 250 502 R  251 503 L 251 504 R  252 505 L 252 506 R  253 507 L 253 508 R  254 509 L 254 510 R

*/

#include <iostream>
#include <map>


using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x){
		data = x;
		left = right = NULL;
	}
};
/* Computes the number of nodes in a tree. */
int height(struct Node* node);
void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);    
}
/* Driver program to test size function*/
int main()
{
	int t;
	scanf("%d", &t);
	cout << "No cases: " << t << endl;
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d",&n);
		cout << "No edges: " << n << endl;
		struct Node *root = NULL;
		struct Node *child;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			scanf("%d %d %c", &n1, &n2, &lr);
			cout << "node: " << n1 << " " << n2 << " " << lr << endl;
			if (m.find(n1) == m.end())
			{
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			}
			else
				parent = m[n1];
			child = new Node(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2]  = child;
		}
		cout << height(root) << endl;
	}
	return 0;
}


/*Please note that it's Function problem i.e.
  you need to write your solution in the form of Function(s) only.
  Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
   struct Node
   {
   int data;
   Node* left, *right;
   }; */
/* Computes the height of binary tree with given root.  */

class auto_inc
{
	public:
	static unsigned int height;
	auto_inc(){ height++; };
	~auto_inc(){ height--; };
	operator unsigned int() { return height; }
};

unsigned int auto_inc::height=0;

int height(Node* node)
{
	static unsigned int max_height = 0;
	// Your code here
	if (node)
	{
		auto_inc ai;
		if (max_height < ai) max_height = ai;
		height(node->left);
		height(node->right);
	}
	return max_height;
}
