import os
import smtplib
from email.message import EmailMessage

def send_email(to, subject, message):
    try:
        email_address = os.environ.get("reeebruh721@gmail.com")
        email_password = os.environ.get("bruh1000")

        if email_address is None or email_password is None:
            # no email address or password
            # something is not configured properly
            print("Did you set email address and password correctly?")
            return False

        # create email
        msg = EmailMessage()
        msg['Subject'] = subject
        msg['From'] = email_address
        msg['To'] = to
        msg.set_content(message)

        # send email
        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
            smtp.login(email_address, email_password)
            smtp.send_message(msg)
        return True
    except Exception as e:
        print("Problem during send email")
        print(str(e))
    return False

send_email("intradrainalertnetwork@gmail.com","Hi","LMAO")