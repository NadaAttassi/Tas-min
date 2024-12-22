// BinaryTree.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Node.h"


int main() {
    //******************1er exemple (simple)
    MinHeap<int> minHeap;

    srand(time(0));

    for (int i = 0; i < 37; i++) {
        minHeap.insert(rand() % 10000); // Insère une valeur aléatoire
    }

    // Affichage structuré de l'arbre binaire
    cout << "Affichage  du tas min (arbre binaire) : " << endl;
    minHeap.display();
    minHeap.levelOrder();
    cout << "Le minimum dans le tas : " << minHeap.getMin() << endl;

    cout << "Suppression de l'element minimum : " << minHeap.removeMin() << endl;
    cout << "Éléments du tas apres suppression : ";
    minHeap.display();
    cout << "Le minimum dans le tas : " << minHeap.getMin() << endl;
    minHeap.levelOrder();

    //******************2eme exemple (10000 valeurs)
    MinHeap<int> minHeap2;

  

    for (int i = 1; i < 10000; i++) {
        minHeap2.insert(i); // Insère une valeur aléatoire
    }

    // Affichage structuré de l'arbre binaire
    cout << "Affichage  du tas min (arbre binaire) : " << endl;
    minHeap2.display();
    minHeap2.levelOrder();
    cout << "Le minimum dans le tas : " << minHeap2.getMin() << endl;

    cout << "Suppression de l'element minimum : " << minHeap2.removeMin() << endl;
    cout << "Éléments du tas apres suppression : ";
    minHeap2.display();
    cout << "resultat apres supression : \n";
    minHeap2.levelOrder();
    cout << "Le minimum dans le tas : " << minHeap2.getMin() << endl;

    //******************3eme exemple (utilisation de strings)
    MinHeap<string> minHeap3;

    // Insérer des chaînes de caractères dans le tas
    minHeap3.insert("Banane");
    minHeap3.insert("Pomme"); 
    minHeap3.insert("Orange"); 
    minHeap3.insert("Mangue"); 
    minHeap3.insert("Fraise"); 

    // Affichage structuré de l'arbre binaire
    cout << "Affichage du tas min (arbre binaire) avec des chaines de caracteres : " << endl; 
    minHeap3.display(); 
    minHeap3.levelOrder(); 
    cout << "Le minimum dans le tas : " << minHeap3.getMin() << endl; 

    cout << "Suppression de l'element minimum : " << minHeap3.removeMin() << endl; 
    cout << "Éléments du tas apres suppression : "; 
    minHeap3.display(); 
    cout << "Le minimum dans le tas : " << minHeap3.getMin() << endl; 

    minHeap3.levelOrder(); 

    return 0;
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
