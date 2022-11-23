#ifndef Casa_hpp
#define Casa_hpp

#include <iostream>

/**
 * A classe Casa, contém informação do dono e número.
 * Aqui poderia vir uma descrição mais detalhada da classe casa, mas como ela é simples
 * essa descrição não é necessária. No entanto, o doxygen trata essa parte de forma diferente
 * da primeira linha. Os métodos devem ser implementados no arquivo Casa.cpp.
 */
class Casa{
    
    private:
        std::string m_dono; //!< nome do dono da casa.
        int m_numero; //!< número da casa. O número deve ser setado pela classe Rua.
    
    public:
        /**
         * Construtor da classe casa.
         * @param dono nome do dono da casa.
         */
        Casa(std::string dono);

        /**
         * Getter do número da casa.
         * @return o número da casa.
         */
        int getNumero();
        /**
         * Setter do número da casa
         * @param n o número que deve ser atribuído à casa
         */
        void setNumero(int n);

        /**
         * Getter do número da casa.
         * @return o nome do dono da casa.
         */
        std::string getDono();
};
#endif