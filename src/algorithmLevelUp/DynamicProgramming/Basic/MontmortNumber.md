/**
 * 
 * 
 * 
*/

```cpp
#include <bits/stdc++.h>

// https://atcoder.github.io/ac-library/document_en/modint.html (included in
// grader)
#include <atcoder/modint>
using mint = atcoder::modint;

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	mint::set_mod(M);
	mint a = 1, b = 0;
	cout << 0 << ' ';
	for (int i = 2; i <= N; i++) {
		mint c = (i - 1) * (a + b);
		cout << c.val() << ' ';
		a = b;
		b = c;
	}
	cout << endl;
}

```S

```cpp

#include <bits/stdc++.h>

// https://atcoder.github.io/ac-library/document_en/modint.html (included in
// grader)
#include <atcoder/modint>
using mint = atcoder::modint;

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	mint::set_mod(M);
	mint a = 1, b = 0;
	cout << 0 << ' ';
	for (int i = 2; i <= N; i++) {
		mint c = (i - 1) * (a + b);
		cout << c.val() << ' ';
		a = b;
		b = c;
	}
	cout << endl;
}
```
