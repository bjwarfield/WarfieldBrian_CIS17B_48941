/* 
 * File:   HelloForm.h
 * Author: Bee-Jay
 *
 * Created on October 20, 2015, 4:08 PM
 */

#ifndef _HELLOFORM_H
#define	_HELLOFORM_H

#include "ui_HelloForm.h"

class HelloForm : public QDialog {
    Q_OBJECT
public:
    HelloForm();
    virtual ~HelloForm();
private:
    Ui::HelloForm widget;
};

#endif	/* _HELLOFORM_H */
