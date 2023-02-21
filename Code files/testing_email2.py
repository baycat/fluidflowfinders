# Importing all the necessary requirements
from smtplib import SMTP
from my_email import email_mine , password_mine
from email_addresses import email1

# Creating the respective object along with the gmail login and port number
smtp_port = SMTP("smtp.gmail.com", 587)
# Establishing a connection to the SMTP server with Transport Layer Security (TLS) mode
smtp_port.ehlo()
# Informing the client to establish a secure connection, either to a TLS or SSL
smtp_port.starttls()
# Logging into your account
smtp_port.login(email_mine , password_mine)

# Creating the contents of the email
subject = "Hello"
body = "Email Automation Project!"
final_message = f"Subject: {subject} \n \n {body}"

# Creating the list of email addresses
address_list = [email1]
smtp_port.sendmail(email_mine, address_list, final_message)
print("Email Sent")
smtp_port.quit()