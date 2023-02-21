import smtplib
import ssl

def send_email():
    port = 465  # For SSL
    smtp_server = "smtp.gmail.com"
    sender_email = "<intradrainalertnetwork@gmail.com>"
    receiver_email = "<intradrainalertnetwork@gmail.com>"
    password = "<wLSD2022>"
    message = """Subject: Arduino Notification\n The switch was turned on."""

    context = ssl.create_default_context()
    with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
        print("Sending email")
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, message)

send_email()