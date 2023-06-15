/*
Anforderung Queue machen mit 2 Stacks
Lösung:
    push immer in Stack 1, vorher alle alten werte in Stack 2 schreiben, dann einfügen in Stack 1, dann alte werte zurück in Stack 2
    so ist der index vom head immer bei dem ältestem element
    definition von stack ist: pop gibt immer das zurück was man zuletzt rein hat
        aka. einfach index zu erhöhen in einem array ist nicht erlaubt
*/