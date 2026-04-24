#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

class CSVParser : public Parser {
private:
    // Caractère utilisé pour séparer les valeurs d'une même ligne dans le fichier CSV (ex: ',' ou ';').
    char _delimiter;

    // Indique si les valeurs de la première ligne du fichier CSV doivent être interprétées comme des noms de colonnes.
    bool _readsColumnNames;

    /*
     * Les données du CSV une fois "parsées", stockées sous forme de tableau 2D de chaînes de caractères
     * (vecteur de vecteurs de string). Chaque ligne du CSV correspond donc à un vecteur de string,
     * et chaque string représente une cellule de la ligne.
     */
    std::vector<std::vector<std::string>> _data;

    /* Les noms des colonnes, donc le contenu de la première ligne du tableau si `_readsColumnNames` est à `true`.
     * Si `_readsColumnNames` est à `false`, ce vecteur doit rester vide. */
    std::vector<std::string> _columnNames;
public:
    /* Constructeur avec paramètres.
     *
     * Des valeurs par défaut sont données aux paramètres.
     * On peut donc appeler le constructeur en lui passant soit 0, 1 ou 2 paramètres.
     * Si on ne lui passe aucun paramètre, ce sont les valeurs par défaut qui seront utilisées.
     * Si on lui en passe un seul, il s'appliquera à `delimiter`, et `readsColumnNames` prendra sa valeur par défaut.
     *
     * Autrement dit, c'est comme si on définissait les trois constructeurs suivants d'un seul coup:
     *
     * CSVParser() : CSVParser(',', true) {}
     * CSVParser(char delimiter) : CSVParser(delimiter, true) {}
     * CSVParser(char delimiter, bool readColumnNames);
     *
     * Les valeurs par défaut ne doivent pas être incluses dans l'implémentation (fichier .cpp). */
    CSVParser(char delimiter=',', bool readColumnNames = true);

    // Accesseurs et mutateurs d'attributs
    char getDelimiter() const;
    void setDelimiter(char delimiter);
    bool readsColumnNames() const;
    void setReadsColumnNames(bool readsColumnNames);
    const std::vector<std::vector<std::string>>& getData() const;
    const std::vector<std::string>& getColumnNames() const;

    /* Méthode qui lit le flux d'entrée et le convertit en matrice de `string` qu'il stocke dans `_data`.
     * La fonction `split` créée précédemment sera utile à l'implémentation de cette méthode.
     * Il ne faudra par ailleurs pas oublier de vider les vecteurs `_data` et `_columnNames` avant de procéder,
     * et de stocker les nouveaux noms de colonnes dans `_columnNames` si `_readsColumnNames` est à `true`.
     * ATTENTION: il ne faut PAS stocker les noms de colonnes dans `_data`!
     */
    void parse(std::istream& in) override;

    /* Retourne l'indice de la colonne correspondant au nom donné en paramètre, ou lance une exception
     * `std::invalid_argument` si aucune colonne ne correspond au nom donné. */
    int getColumnIndex(const std::string& columnName) const;

    /* Retourne la ligne de la matrice correspondant à l'indice reçu en paramètre, ou lance une exception
     * `std::out_of_range` si l'indice est invalide. */
    const std::vector<std::string>& getRow(size_t index) const;

    /* Retourne la chaîne de caractères présente à la ligne et la colonne spécifiés.
     * Cette méthode existe en deux versions: une qui reçoit l'indice de la colonne, et une autre qui reçoit plutôt
     * le nom de la colonne. Lance une exception `std::out_of_range` au besoin. */
    const std::string& getString(size_t row, size_t column) const;
    const std::string& getString(size_t row, const std::string& columnName) const;

    /* Retourne la valeur présente à la ligne et la colonne spécifiée, en la convertissant d'abord en `int`.
     * Utilisez la fonction `std::stoi` pour convertir la chaîne de caractères en `int`.
     */
    int getInt(size_t row, size_t column) const;
    int getInt(size_t row, const std::string& columnName) const;

    /* Retourne la valeur présente à la ligne et la colonne spécifiée, en la convertissant d'abord en `double`.
     * Utilisez la fonction `std::stod` pour convertir la chaîne de caractères en `double`.
     */
    double getDouble(size_t row, size_t column) const;
    double getDouble(size_t row, const std::string& columnName) const;

    // Accesseur du nombre de lignes présentes dans `_data`
    size_t getNumRows() const;

    /* Accesseur du nombre de colonnes.
     * Attention: doit retourner le bon résultat même s'il n'y a pas de noms de colonnes! */
    size_t getNumColumns() const;
};