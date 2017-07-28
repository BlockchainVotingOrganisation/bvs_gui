#ifndef OPTIONREPOSITORY_H
#define OPTIONREPOSITORY_H

#include <QJsonDocument>
#include "Classes/Domain/Model/option.h"

class OptionRepository
{
public:
    OptionRepository();

    Option findOptionByJsonStr(QJsonDocument optionJdoc);
};

#endif // OPTIONREPOSITORY_H
