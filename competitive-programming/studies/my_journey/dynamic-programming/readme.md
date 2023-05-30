# Programação Dinâmica

### Conteúdos

- [Programação Dinâmica - Vitor Colombo (USP)](https://youtu.be/eLqKBivIxJI)
- [Programação Dinâmica e número de Fibonacci - Carla Negri Lintzmayer (UFABC)](https://youtu.be/7ZI0U8nJ_8E)
- [Programação Dinâmica - Bernardo Amorim (UFMG)](https://youtu.be/IHuZAgKGM6Y)

### Fibonacci

###### Questão

Dado uma limitação de tempo de execução de $t_{exe} < 0.5 \text{ segundos}$, faça uma função recursiva que cálcule e mostre o valor de fibonacci para uma determinada entrada $0 > x > 50$.

> **Entrada**
>
> 50

> **Saída**
>
> 12586269025

###### Solução

Exemplo do código de fibonacci utilizando função recursiva e os conhecimentos de programação dinâmica para resolver a questão anterior e suas limitações.

```cpp
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

ll memo[100010];
ll N;

ll fib(ll n) {
	if (memo[n] == -1) {
		memo[n] = fib(n-1) + fib(n-2);
		cout << " " << memo[n];
	}
	return memo[n];
}

int main(){ _
	cin >> N;
	memset(memo, -1, sizeof memo);
	memo[0]=0;memo[1]=1;memo[2]=1;
	cout << "0 1 1";
	N=N-1;
    fib(N);
    cout << endl;
    return 0;
}
```

O código acima tem uma limitação por tamanho do tipo, o tipo _long long_ irá estourar quando o valor exceder seu limite de $9\times10^{18}$, ou seja, para valores maiores que $9.000.000.000.000.000.000$ o código acima irá quebrar.

Dessa forma podemos dizer que o código acima calcula até fibonacci de $92$, que equivale a $7.540.113.804.746.346.429$, o fibonacci de $93$ será $12.200.160.415.121.876.738$, excedendo o valor limite de _long long_.

Poderia também utilizar o _unsigned long long_, mas a diferença seria pouca nesse caso, pois só iria abranger o $93$, mas em seguida quebraria no fibonacci de $94$ que é maior que o nosso novo limite de _unsigned long long_ ($18\times10^{18}$).
