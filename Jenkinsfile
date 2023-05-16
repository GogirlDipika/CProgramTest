pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'main', credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git'
            }
        }
        stage('Cppcheck') {
            steps {
                bat 'cppcheck --platform=win64 --inconclusive --enable=all --xml-version=2 --xml cppcheck.xml'
            }
        }
        stage('Quality Gate') {
            steps {
                script{
                    // Read Cppcheck XML file into a string
                    def xmlString = readFile 'cppcheck.xml'

                    // Parse XML string using XmlSlurper
                    def xml = new XmlSlurper().parseText(xmlString)

                    // Access elements in the XML document
                    def errorCount = xml.@errors.toInteger()
                    //def warningCount = xml.@warnings.toInteger()

                    // Quality Gate criteria
                    def maxErrors = 5
                    //def maxWarnings = 10

                    // Check if quality gate conditions are met
                    //if (errorCount <= maxErrors && warningCount <= maxWarnings) {
                    if (errorCount <= maxErrors) {
                        echo "Quality Gate: Passed"
                    } else {
                        error "Quality Gate: Failed - Exceeded maximum errors or warnings"
                    }
                    }
            }
        }
    }
    post {
        always {
            publishCppcheck pattern:'cppcheck.xml'
        }
    }
}
