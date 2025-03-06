# 🔐 Desafio de Criptografia - Março 2025  

## 📖 Sobre o Projeto  

Este projeto faz parte de um desafio de programação que participo com amigos a cada 15 dias. O desafio de março consiste em desenvolver um sistema de criptografia baseado em uma função específica que gera a chave de criptografia a partir de dois valores de entrada.  

O objetivo é criar a **melhor, mais rápida e mais eficiente** implementação, garantindo que o algoritmo seja sólido, funcional e seguro.  

## ❓ Motivação  

A ideia do desafio é aprimorar habilidades em algoritmos, segurança e manipulação de dados binários. Além disso, buscamos aprender mais sobre técnicas criptográficas e como a geração de chaves pode influenciar a segurança de um sistema.  

Ao impor restrições como **tamanho fixo de chave** e **unicidade dos bits no retorno da função de derivação**, o projeto desafia a criatividade e a capacidade de encontrar soluções otimizadas.  

Este tipo de exercício é fundamental para quem deseja aprofundar-se em segurança da informação, engenharia reversa e manipulação de dados de baixo nível.  

## 🔢 Especificação Técnica  

A criptografia deve seguir as seguintes regras:  

### 📌 Geração da Chave  
A chave de criptografia é derivada de dois valores (`x` e `y`) por meio da função `f`, que segue a seguinte definição:  

```
f<K,T>(x:K, y:K) -> T where  
  sizeof(K) == 32;  
  sizeof(T) >= 32;  
```

- `K`: Tipo dos valores `x` e `y`, de **exatamente 32 bytes**.  
- `T`: Chave de criptografia gerada, que deve ter **pelo menos 32 bytes**.  
- A função `f` deve garantir que os bits de `T` sejam **únicos** para cada par `(x, y)`, ou seja, dado um par fixo `(x, y)`, o valor `T` deve sempre ser o mesmo e não pode ser gerado aleatoriamente.  

### 🔄 Processo de Criptografia  
Supondo um texto de entrada:  
```c
const char *content = "Hello World";
```
O código abaixo deve ser válido:  
```c
K x = getX();
K y = getY();
T encrypting_key = f(x, y);

assert(sizeof(x) == 32 && sizeof(y) == sizeof(x));
assert(sizeof(encrypting_key) > 32);

UInt8Array encrypted_content = encrypt(content, encrypting_key);
printf("%s", encrypted_content); // Deve imprimir os bytes criptografados

assert(encrypted_content.length >= 16);

UInt8Array returned_content = decrypt(encrypted_content, encrypting_key);
printf("%s", returned_content); // Deve imprimir "Hello World"

assert(returned_content.length == strlen(content));
for (size_t i = 0; i < returned_content.length; i++) {
    assert(returned_content[i] == content[i]);
}
```
⚠️ **Observação:** O conteúdo de `encrypted_content` não precisa ser um texto legível em UTF-8, pois apenas os bits importam.  

## 🏆 Critérios de Avaliação  

O desafio consiste em criar a melhor implementação possível, levando em conta os seguintes aspectos:  

✅ **Corretude:** O código deve seguir as regras estabelecidas e funcionar corretamente.  
🚀 **Eficiência:** Implementações mais rápidas e otimizadas terão vantagem.  
🔐 **Segurança:** Embora o desafio não envolva criptografia de nível militar, abordagens mais robustas serão valorizadas.  
📝 **Clareza do Código:** O código deve ser bem escrito, organizado e documentado.  

## 🔧 Tecnologias Utilizadas  
- **Linguagem:** C  
- **Compilador recomendado:** GCC ou Clang  
- **Bibliotecas auxiliares:** *(Dependendo da implementação, pode-se usar OpenSSL, libsodium ou outras, mas o ideal é uma implementação pura em C)*  

## Quer participar também?🚀   
1. Clone este repositório  
2. Desenvolva sua implementação seguindo as regras  
3. Teste e otimize seu código  
4. Compare os resultados com os dos seus amigos  

---

💡 **Este desafio é uma excelente oportunidade para aprimorar habilidades em C e criptografia. Que vença o melhor!** 🚀
