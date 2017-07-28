#include "optionrepository.h"
#include "Classes/Domain/Model/option.h"
#include <QJsonObject>

OptionRepository::OptionRepository()
{

}

Option OptionRepository::findOptionByJsonStr(QJsonDocument optionJdoc) {

    Option option;

    if (optionJdoc.isObject() == true) {
        QJsonObject jsonObject = optionJdoc.object();
        option.setName(jsonObject.value("name").toString());
        option.setWalletAddress(jsonObject.value("walletaddress").toString());
    }
    return option;
}
