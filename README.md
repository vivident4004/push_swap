*This project has been created as part of the 42 curriculum by aflorea*

# Push swap (spingi scambia)

## Descrizione
Questo progetto ha l'obiettivo di ordinare una pila di numeri interi utilizzando il minor numero possibile di mosse. A disposizione si hanno due pile (denominate A e B) e un insieme limitato d'istruzioni per manipolarle.

La sfida principale risiede nella scelta e nell'implementazione di un algoritmo efficiente in termini di complessità algoritmica, dovendo gestire diverse configurazioni di numeri (da pochi elementi fino a centinaia).

Il progetto include anche una parte bonus (*checker*), un programma utile a verificare se la sequenza d'istruzioni generata ordina correttamente la pila.

## Istruzioni

### Compilazione
Il progetto utilizza un `Makefile` per gestire la compilazione. Sono disponibili le seguenti regole:

*   `make`: compila la parte obbligatoria, generando l'eseguibile `push_swap`.
*   `make bonus`: compila la parte opzionale, generando l'eseguibile `checker`.
*   `make clean`: rimuove le filze oggetto generate durante la compilazione.
*   `make fclean`: rimuove le filze oggetto e gli eseguibili.
*	`make valgrind`: avvia il programma e controlla che non ci siano perdite di memoria.
*   `make re`: esegue una pulizia completa e ricompila tutto.

### Esecuzione
Per eseguire il programma principale:

```bash
./push_swap 2 1 3 6 5 8
```

Il programma stamperà sull'uscita canonica la lista di operazioni necessarie per ordinare i numeri.

Per utilizzare il verificatore (bonus):
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Se l'ordinamento è corretto, il verificatore stamperà `OK`, altrimenti `KO`. In caso di errori nei parametri, verrà stampato `Error`.

## Risorse
### Riferimenti teorici

Per lo sviluppo di questo progetto sono stati consultati materiali relativi a:
*	Strutture dati: approfondimento sul funzionamento delle pile e liste concatenate. In particolare, su come realizzare un vettore circolare con gl'indici (appunti dal materiale universitario del corso «Fondamenti di informatica» dell'Unifi)
*	Complessità algoritmica: studio di vari algoritmi di ordinamento e della loro complessità, con relativa implementazione.

### Utilizzo dell'intelligenza artificiale

Come richiesto dalle linee guida, si specifica che l'i.a. è stata utilizzata come supporto nelle seguenti fasi:

* Ottimizzazione del Makefile: supporto nella gestione delle dipendenze comuni tra la parte obbligatoria e quella bonus; integrazione dell'arte ASCII e scrittura delle istruzioni per i comandi delle prove; aiuto nella scrittura dei commenti `@brief`, `@param` e simili come documentazione delle funzioni; scrittura di regole specifiche per le prove come `make test500` e `make valgrind`.
* Sbacatura  della logica del verificatore: analisi del codice per individuare errori nella gestione delle stringhe in ingresso e nell'uso delle funzioni di libreria condivise.
* Suggerimenti per ripulire il codice e migliorare la leggibilità, e per avere un'architettura solida e modulare. Alcuni nomi di funzioni, o la loro suddivisione in piú parti, sono stata suggeriti dall'i.a., ma l'intero codice è stato scritto a mano da *aflorea*.

## Logica del funzionamento
L'algoritmo sviluppato per questo progetto si basa su un approccio «goloso» (*greedy*, in inglese), ottimizzato attraverso una fase preliminare di distribuzione strategica dei numeri. Il flusso di esecuzione si articola in tre fasi principali:
1. Indicizzazione e preordinamento
Prima di iniziare le operazioni, i numeri originali vengono sostituiti con il loro indice di rango (da 0 a N-1). Poiché i valori sono ora consecutivi, il valore medio corrisponde esattamente alla mediana, cosí calcolabile istantaneamente, per la suddivisione iniziale.

2. Distribuzione strategica (da A a B)
Invece di trasferire i numeri nella pila B in modo casuale, l'algoritmo li divide sfruttando la mediana calcolata nella fase precedente.
	*	I numeri inferiori alla mediana vengono spinti nella pila B.
	*	I numeri superiori vengono anch'essi spinti, ma la pila B viene ruotata per posizionarli sul fondo.
Questa suddivisione crea un ordinamento grossolano all'interno della pila B, riducendo drasticamente il numero di rotazioni necessarie nella fase successiva. Si continua fino a lasciare nella pila A solo tre elementi, che vengono ordinati rapidamente.

3. Algoritmo goloso (da B ad A)
Per ogni elemento presente nella pila B, l'algoritmo calcola il «costo» necessario per riportarlo nella posizione corretta all'interno della pila A.
	*	Identificazione dell'obiettivo (*target*): per un dato numero in B, l'obiettivo in A è il numero piú piccolo tra quelli che sono maggiori del numero stesso (o il minimo assoluto se non ne esistono di maggiori).
	*	Calcolo del costo: viene calcolato quante rotazioni servono per portare l'elemento in cima a B e quante per portare il suo bersaglio in cima ad A.
	*	Scelta ed esecuzione: l'algoritmo confronta i costi di tutti gli elementi in B e sceglie quello che richiede meno mosse totali. Vengono privilegiate le mosse doppie (che ruotano entrambe le pile simultaneamente) per massimizzare l'efficienza.

Una volta svuotata la pila B, una rotazione finale assicura che il numero minimo della pila A si trovi in cima, completando l'ordinamento.